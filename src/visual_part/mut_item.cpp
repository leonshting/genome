#include "mut_item.h"


Mut_item::Mut_item(int _x, QString letter,QBrush _brush, QPen _pen,QGraphicsItem *parent) :/*describes objects for drawing*/
    QGraphicsItem(parent)
{
    brush = _brush;
    pen= _pen;
    le = letter;
    x = _x;
    QString s;
    setToolTip(s.sprintf("%d ",x) + letter);
}

void Mut_item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)/*describes function for drawing*/
{
    QRectF rec = boundingRect();
    painter->setBrush(brush);
    painter->setPen(pen);
    painter->drawRect(rec);
}

QRectF Mut_item::boundingRect() const       /*colour bound of window*/
{
    return QRectF(x,10,5,5);
}

