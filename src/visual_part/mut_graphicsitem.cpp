#include "mut_graphicsitem.h"
#include <QListIterator>
#include <QPen>
#include <QPainter>
#include <QDebug>

#include <mut_item.h>
#include <prot_item.h>

mut_GraphicsItem::mut_GraphicsItem()
{
}

void mut_GraphicsItem::configureItem(QGraphicsScene *s, QString file1)
{
    parsed_one = CSV::parseFromFile(file1,',',0);
    QPen pen(Qt::black);
    QBrush brush(Qt::blue);
    QListIterator<QStringList> i(parsed_one);

    while(i.hasNext())
    {
        QStringList list = i.next();
        int a = list[0].toInt();
        QString b = list[1];
        Mut_item *item = new Mut_item(a,b,brush,pen);
        s->addItem(item);
    }
}

void mut_GraphicsItem::configureProt(QGraphicsScene *s, QString file2, int length)
{
    int is=1;
    parsed_two = CSV::parseFromFile(file2,'\t',2);
    QPen pen_mid(Qt::green);
    QPen pen_prot(Qt::red);
    QBrush brush(Qt::blue);
    prot_item *item2 = new prot_item(0,length,5,0,brush,pen_mid,0);
    s->addItem(item2);
    QListIterator<QStringList> i(parsed_two);
    while(i.hasNext())
    {
        QStringList list = i.next();
        QStringList tmp = list[0].split("..");
        int x1 = tmp[0].toInt();
        int x2 = tmp[1].toInt();
        QString b = list[8];
        prot_item *item = new prot_item(x1,x2,10,b,brush,pen_prot,is);
        is = (is==1)?2:1;
        s->addItem(item);
    }

}
