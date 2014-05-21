#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "prot_item.h"

#include <QByteArray>
#include <QProgressBar>
#include <QIcon>
#include <QScrollBar>
#include <math.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("LIG");
    QIcon ico(":images/LIG.png");
    this->setWindowIcon(ico);
    d = new Daemon();
    item = new mut_GraphicsItem;
    spec_line = new QLineF;
    f = false;
    zoom_a = false;
    z=0;
    QObject::connect(d->to_pileup, SIGNAL(finished(int)), d, SLOT(mut_st()));
    QObject::connect(d->to_pileup, SIGNAL(readyReadStandardOutput()), this, SLOT(newData_received()));
    QObject::connect(d->to_qua, SIGNAL(finished(int)), this, SLOT(push_paint()));
    QObject::connect(ui->graphicsView->horizontalScrollBar(),SIGNAL(valueChanged(int)),this, SLOT(show_place(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionBAM_triggered()
{
    d->bam = QFileDialog::getOpenFileName(this, tr("Load BAM file"), "", "*.bam");
    if(!d->bam.isEmpty()) ui->textBrowser->addItem(d->bam + " is loaded");
}

void MainWindow::on_actionFASTA_triggered()
{
    d->fasta = QFileDialog::getOpenFileName(this, tr("Load FNA file"), "", "*.fna");
    if(!d->fasta.isEmpty()) ui->textBrowser->addItem(d->fasta + " is loaded");
}

void MainWindow::on_actionFASTA_ptt_triggered()
{
    d->ptt = QFileDialog::getOpenFileName(this, tr("Load PTT file"), "", "*.ptt");
    if(!d->ptt.isEmpty()) ui->textBrowser->addItem(d->ptt + " is loaded");
}

void MainWindow::on_pushButton_clicked()
{
    d->update_is_loaded();
    if(d->is_loaded)
        ui->textBrowser->addItem("Mutation detection started...");
    else
    {
        ui->textBrowser->addItem("You have not loaded somefiles, check text upper.");
    }
    d->execute_everything();
}

void MainWindow::newData_received()
{

    QByteArray da = d->to_pileup->readAllStandardOutput();
    int tmp = int(da[0]);
    if(!d->is_pileup_ended)
        ui->progressBar->setValue(tmp);
    else
    {
        QString tmp2(da);
        d->index_size = tmp2.toInt();
        d->set_imsorry(ui->graphicsView_2->width()-5);
        d->setup_scenes();
    }
    if(tmp<100) d->is_pileup_ended = false;
    else if(tmp == 100)
    {
        d->is_pileup_ended = true;
        ui->textBrowser->addItem("pileup ended, start of q_marker is being handled");
    }
}

void MainWindow::push_paint()
{
    ui->textBrowser->addItem("q_marker is ended, visualization started");
    item->configureItem(d->dna, "as1.qualities");
    item->configureProt(d->dna, d->ptt, d->index_size);
    item->configure_histogram(d->pr,d->index_size/(ui->graphicsView_2->width()));

    ui->graphicsView->setScene(d->dna);
    ui->graphicsView_2->setScene(d->pr);
    ui->graphicsView->show();
    ui->graphicsView_2->show();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    ui->graphicsView->resize(this->width()-ui->graphicsView->x()-10,ui->graphicsView->height());
    ui->textBrowser->resize(this->width()-ui->textBrowser->x()-10,ui->textBrowser->height());
}

void MainWindow::show_place(int a)
{

    if(!zoom_a)
    {
        qreal x = qreal(a)/(qreal(d->index_size)*pow(.8, z));
        QPen pen(Qt::green);
        spec_line->setLine(x*ui->graphicsView_2->width(),0,x*ui->graphicsView_2->width(),ui->graphicsView_2->height()-1);
        if(!f)
        {
            it = d->pr->addLine(*spec_line,pen);
        }
        else
        {
            it->moveBy(spec_line->x1()-it->x(),0);

        }
        f = true;
    }
    else
    {
        zoom_a = false;
    }

}

void MainWindow::on_pushButton_3_clicked()
{
    zoom_a = true;
    ui->graphicsView->scale(.8,1);
    z++;
    ui->pushButton_2->setEnabled(true);
    if(z>10) ui->pushButton_3->setDisabled(true);
}



void MainWindow::on_pushButton_2_clicked()
{
    zoom_a = true;
    ui->graphicsView->scale(1.25, 1);
    z--;
    if(z==0) ui->pushButton_2->setDisabled(true);
    if(z<=10) ui->pushButton_3->setEnabled(true);

}
