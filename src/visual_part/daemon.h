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
    QGraphicsScene *pr;
    bool is_loaded;
    int imsorry_width;
    void set_imsorry(int n){imsorry_width = n;}
private:
public slots:
    void pileup_st();
    void mut_st();
    void setup_scenes();
};

#endif // DAEMON_H
