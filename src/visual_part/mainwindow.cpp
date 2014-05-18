#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "prot_item.h"

#include <QByteArray>
#include <QProgressBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    d = new Daemon();
    item = new mut_GraphicsItem;
    QObject::connect(d->to_pileup, SIGNAL(finished(int)), d, SLOT(mut_st()));
    QObject::connect(d->to_pileup, SIGNAL(readyReadStandardOutput()), this, SLOT(newData_received()));
    QObject::connect(d->to_qua, SIGNAL(finished(int)), this, SLOT(push_paint()));
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

    ui->graphicsView->setScene(d->dna);
    ui->graphicsView->show();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    ui->graphicsView->resize(this->width()-ui->graphicsView->x()*2,ui->graphicsView->height());
    ui->textBrowser->resize(this->width()/2-ui->textBrowser->x(),ui->textBrowser->height());
}
