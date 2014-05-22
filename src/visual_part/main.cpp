#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);      /*argc is the number of command-line arguments,
                                       and argv is that array list of command-line arguments*/
    QCoreApplication::setApplicationName("LIG"); /*he QApplication class manages the GUI 
                                                application's control flow and main settings*/
    MainWindow w;
    w.show();

    return a.exec();    /*provides an event endless loop*/
}
