#ifndef PROT_ITEM_H
#define PROT_ITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>
#include <QString>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>
#include <QPen>

class prot_item : public QGraphicsItem
{
public:
    prot_item(int _x1, int _x2, int _width, QString _name, QBrush _brush, QPen _pen, int _level = 0, QGraphicsItem *parent = 0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QString name;
    int x1, x2, width;
    QBrush brush;
    QPen pen;
    int level;
};

#endif // PROT_ITEM_H
