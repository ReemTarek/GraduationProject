#include "obstacle.h"

#include<QBrush>
#include<QPainter>
#include <iostream>
using namespace std;
Obstacle::Obstacle()
{
    setFlag(ItemIsMovable);
    QColor blue30 = Qt::blue;
    blue30.setAlphaF( 0.3 );
    color = blue30;

}
QRectF Obstacle::boundingRect() const
{
     return QRectF(10, 10, 30, 50);

}

void Obstacle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    setScale(0.7);
    QRectF Slot = boundingRect();

    QBrush brush(color);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->fillRect(Slot, brush);
    painter->drawRect(Slot);
//    setRotation(45);
//    cout<<"paintes"<<endl;

  //  cout<<"rotatoted"<<endl;
    //update(10,10,30,50);
    QPointF newpoint = mapToParent((boundingRect().width()),(boundingRect().width()+ 10));
    if(!scene()->sceneRect().contains(newpoint)){
        //move back in bounds
    //    cout<<"out of bound!!!"<<endl;
//        setPos(10,10);

    }
}
