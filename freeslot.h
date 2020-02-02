#ifndef FREESLOT_H
#define FREESLOT_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <garageitems.h>

class FreeSlot : public GarageItems
{
public:
    FreeSlot();
    FreeSlot(int theta);
    int theta = 0;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) ;

};

#endif // FREESLOT_H
