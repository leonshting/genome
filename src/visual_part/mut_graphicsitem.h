#ifndef MUT_GRAPHICSITEM_H
#define MUT_GRAPHICSITEM_H

#include <QGraphicsItemGroup>
#include <QList>
#include <QStringList>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <csv.h>


class mut_GraphicsItem
{

public:
    mut_GraphicsItem();
    QList<QStringList> parsed_one, parsed_two, parsed_three;
    void configureItem(QGraphicsScene *s, QString file1, QString file2);
    void configureProt(QGraphicsScene *s, QString file2, int length);
    void configure_histogram(QGraphicsScene *s, int perpix);
signals:

public slots:

};

#endif // MUT_GRAPHICSITEM_H
