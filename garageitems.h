#ifndef GARAGEITEMS_H
#define GARAGEITEMS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGraphicsItem>
#include<QRectF>
#include<QColor>
class GarageItems : public QGraphicsItem
{

public:
    GarageItems();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;
    QRectF boundingRect() const;
    QColor color;
    QColor getColor();

};

#endif // GARAGEITEMS_H
