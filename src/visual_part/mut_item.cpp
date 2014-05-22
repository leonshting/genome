#include "mut_item.h"


Mut_item::Mut_item(int _x, QString letter, bool non_sy,QBrush _brush, QPen _pen,QString pr_replacement,QGraphicsItem *parent) :/*describes objects for drawing*/
    QGraphicsItem(parent)
{
    brush = _brush;
    pen= _pen;
    le = letter;
    x = _x;
    QString s;
    strange = non_sy;
    setToolTip(s.sprintf("%d ",x) + letter+ "\n" + pr_replacement);
}

void Mut_item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)/*describes function for drawing*/
{
    QRectF rec = boundingRect();
    painter->setBrush(brush);
    if(!strange)
    {
        painter->setPen(pen);
        painter->setBrush(brush);
    }
    else
    {
        painter->setPen(pen);
        painter->setBrush(QBrush(QColor(255,102,255)));

    }
    painter->drawRect(rec);
}

QRectF Mut_item::boundingRect() const       /*colour bound of window*/
{
    return QRectF(x,10,5,5);
}

