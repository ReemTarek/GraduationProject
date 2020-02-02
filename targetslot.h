#ifndef TARGETSLOT_H
#define TARGETSLOT_H

#include <garageitems.h>

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class TargetSlot : public GarageItems
{
public:
    TargetSlot();
    TargetSlot(int degree);
    QRectF boundingRect() const;
    int theta=0;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) ;
};

#endif // TARGETSLOT_H
