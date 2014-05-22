#ifndef MUT_ITEM_H
#define MUT_ITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>
#include <QString>
#include <QGraphicsSceneMouseEvent>

class Mut_item :public QGraphicsItem
{

public:
    explicit Mut_item(int _x, QString letter, bool non_sy,QBrush _brush, QPen _pen,QString pr_replacement=0,QGraphicsItem *parent=0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QString le;
    int x;
    QBrush brush;
    QPen pen;
    bool strange;
protected:
signals:

public slots:

};

#endif // MUT_ITEM_H
