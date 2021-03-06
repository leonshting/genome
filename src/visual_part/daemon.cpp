#include "daemon.h"
#include <QProcess> /*used to start external programs and to communicate with them*/
#include <QObject>   /*to use signals,slots and other meta-object features*/


Daemon::Daemon()
{
    is_loaded = false;
    to_pileup = new QProcess;
    to_qua = new QProcess;
    to_anno = new QProcess;
    is_pileup_ended = false;
    dna = new QGraphicsScene;
    pr = new QGraphicsScene;
}

bool Daemon::execute_everything()
{
    if(is_loaded)
    {
        pileup_st();
        return true;
    }
    else return false;
}

void Daemon::update_is_loaded()
{
    is_loaded = !bam.isNull() && !fasta.isEmpty() && !ptt.isEmpty();
}

void Daemon::pileup_st()
{
    QString program = "/home/leonsht/Programming/genome/build/pileup";
    QStringList arguments;
    arguments << bam << fasta << "as.pileup";
    to_pileup->start(program, arguments);
}

void Daemon::anno_st()
{
    QString program = "/home/leonsht/Programming/genome/build/anno";
    QStringList arguments;
    arguments << ptt << fasta << "as1.qualities";
    to_anno->start(program, arguments);
}

void Daemon::mut_st()
{
    QString program = "/home/leonsht/Programming/genome/build/quality_marker";
    QStringList arguments;
    arguments << "as.pileup" << "as.qualities" << "as1.qualities";
    to_qua->start(program, arguments);
}

void Daemon::setup_scenes()
{
    dna->setSceneRect(0,0,index_size,100);
    pr->setSceneRect(0,0,imsorry_width,68);
}
