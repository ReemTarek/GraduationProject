#ifndef OBSTACLE_H
#define OBSTACLE_H
#include <garageitems.h>


#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class Obstacle : public GarageItems
{

public:
    Obstacle();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) ;

};

#endif // OBSTACLE_H
