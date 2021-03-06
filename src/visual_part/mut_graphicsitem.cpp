#include "mut_graphicsitem.h"
#include <QListIterator>
#include <QPen>
#include <QPainter>
#include <QDebug>
#include <QPainterPath>

#include <mut_item.h>
#include <prot_item.h>

/*class that controls the rendering*/
mut_GraphicsItem::mut_GraphicsItem()  
{
}

void mut_GraphicsItem::configureItem(QGraphicsScene *s, QString file1, QString file2)
{
    parsed_one = CSV::parseFromFile(file1,',',0);
    parsed_three = CSV::parseFromFile(file2,',',0);
    QPen pen(Qt::black);
    QBrush brush(Qt::blue);
    QListIterator<QStringList> i(parsed_one);
    QListIterator<QStringList> j(parsed_three);

    while(i.hasNext())
    {
        QStringList list = i.next();
        QStringList list2 = j.next();
        int a = list[0].toInt();
        QString b = list[1];
        Mut_item *item = new Mut_item(a,b,!list2[3].isEmpty(),brush,pen,(!list2[3].isEmpty())?(list2[2]+"->"+list2[3]):list2[2]);
        s->addItem(item);
    }
}

void mut_GraphicsItem::configureProt(QGraphicsScene *s, QString file2, int length) /*reference and mutations*/
{
    int is=1;
    parsed_two = CSV::parseFromFile(file2,'\t',2);
    QPen pen_mid(Qt::green);   /*obvodka poloski*/
    QPen pen_prot(Qt::red);     /*obvodka poloski*/
    QBrush brush(Qt::blue);     /*zapolnenie poloski*/
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

void mut_GraphicsItem::configure_histogram(QGraphicsScene *s, int perpix)   /*plotnost of mutations*/
{
    int num = 0;
    QPen pen(Qt::black);
    QBrush brush(Qt::blue);
    QVector<int> histog;
    QListIterator<QStringList> i(parsed_one);
    QPainterPath p,se;
    while(i.hasNext())
    {
        QStringList list = i.next();
        int a = list[0].toInt();
        if(a<(num*perpix))
        {
            histog[num-1]++;
        }
        else
        {
            if (num==0)p.moveTo(0, 0);
            else
            {
                p.moveTo(num, 0);
                p.lineTo(num,histog[num-1]);
            }
            num++;
            histog.push_back(1);
        }
    }
    s->addPath(p,pen,brush);
}
