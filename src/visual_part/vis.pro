/*like a makefile-collector*/

#-------------------------------------------------
#
# Project created by QtCreator 2014-05-16T00:20:05
#
#-------------------------------------------------


QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = vis
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    daemon.cpp \
    mut_graphicsitem.cpp \
    csv.cpp \
    mut_item.cpp \
    prot_item.cpp

HEADERS  += mainwindow.h \
    daemon.h \
    mut_graphicsitem.h \
    csv.h \
    mut_item.h \
    prot_item.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc

