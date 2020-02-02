#include "targetslot.h"

#include<QBrush>
#include<QPainter>
#include <iostream>
using namespace std;
TargetSlot::TargetSlot()
{
    setFlag(ItemIsMovable);
    QColor green30 = Qt::green;
    green30.setAlphaF( 0.3 );
    color = green30;

}
TargetSlot::TargetSlot(int theta)
{
    setFlag(ItemIsMovable);
    this->theta =theta;
    QColor green30 = Qt::green;
    green30.setAlphaF( 0.3 );
    color = green30;

}
QRectF TargetSlot::boundingRect() const
{
    return QRectF(10, 10, 100, 50);
}

void TargetSlot::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    setScale(0.7);
    QRectF Slot = boundingRect();

    QBrush brush(color);
    painter->fillRect(Slot, brush);
    painter->drawRect(Slot);
    setRotation(theta);
    QPointF newpoint = mapToParent((boundingRect().width()),(boundingRect().width()+
                                                               10));
    if(!scene()->sceneRect().contains(newpoint)){
        //move back in bounds
        //cout<<"out of bound!!!"<<endl;
        //setPos(10,10);

    }
}
