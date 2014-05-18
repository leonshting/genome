#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QResizeEvent>

#include <daemon.h>
#include <mut_graphicsitem.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionBAM_triggered();

    void on_actionFASTA_triggered();

    void on_actionFASTA_ptt_triggered();

    void on_pushButton_clicked();

    void newData_received();

    void push_paint();

protected:
    void resizeEvent(QResizeEvent *event);

private:
    Ui::MainWindow *ui;
    Daemon *d;
    mut_GraphicsItem * item;
};

#endif // MAINWINDOW_H
