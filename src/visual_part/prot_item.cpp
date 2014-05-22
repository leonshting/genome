#include "prot_item.h"

prot_item::prot_item(int _x1, int _x2, int _width, QString _name,QBrush _brush, QPen _pen, int _level, QGraphicsItem *parent) :/*describes objects for drawing*/
    QGraphicsItem(parent)
{
    brush = _brush;
    pen= _pen;
    name = _name;
    x1 = _x1;
    x2 = _x2;
    width  = _width;
    level = _level;
    QString s1,s2;
    setToolTip(name+'\n'+ s1.sprintf("%d",x1)+ ".." + s2.sprintf("%d",x2));
}

void prot_item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) /*describes function for drawing*/
{
    QRectF rec = boundingRect();
    painter->setBrush(brush);
    painter->setPen(pen);
    painter->drawRect(rec);
}

QRectF prot_item::boundingRect() const  /*colour bound of window*/
{
    return QRectF(x1,55+level*(width+5),x2-x1,width);
}
