#ifndef DAEMON_H
#define DAEMON_H

#include <QString>
#include <QWidget>
#include <QProcess>
#include <QGraphicsScene>


class Daemon:public QObject
{
    Q_OBJECT
public:
    Daemon();
    bool execute_everything();
    void update_is_loaded();
    QString bam, fasta, ptt;
    QProcess *to_pileup, *to_qua;
    bool is_pileup_ended;
    int index_size;
    QGraphicsScene *dna;
    QGraphicsScene *prot;
    bool is_loaded;

private:
public slots:
    void pileup_st();
    void mut_st();
    void setup_scenes();
};

#endif // DAEMON_H
