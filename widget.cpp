#include "widget.h"
#include "ui_widget.h"
#include<QGraphicsView>
#include "freeslot.h"
#include "occupiedslot.h"
#include "targetslot.h"
#include "obstacle.h"
#include <iostream>
#include<QtCore>
#include<QtGui>
#include<QPointF>
#include<QDebug>
using namespace std;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,430,341);
    scene->setBackgroundBrush(Qt::Dense7Pattern);
    car = new Car();
    targetSlot = new TargetSlot();
    scene->addItem(targetSlot);
    scene->addItem(car);

    ui->graphicsView->setScene(scene);


    timer = new QTimer(this);

connect(ui->movetotarget, SIGNAL(clicked(bool)), this, SLOT(on_move_to_target_clicked()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_FreeSlot_clicked()
{FreeSlot *free = new FreeSlot;
     scene->addItem(free);
     cout<<"entered here"<<endl;
}

void Widget::on_BusySlot_clicked()
{
    OccupiedSlot *Busy = new OccupiedSlot();
    scene->addItem(Busy);
//    qDebug()<<"p"<<view->itemAt(Busy->x(), Busy->y());
}

void Widget::on_TargetSlot_clicked()
{
    targetSlot->theta=0;
    targetSlot->update();
}

void Widget::on_Obstacle_clicked()
{
    Obstacle *block = new Obstacle;
    //QTransform q;
   // q.rotate(45,block);
    scene->addItem(block);

}

void Widget::on_TargetSlot_2_clicked()
{
     targetSlot->theta = 45;
     targetSlot->update();
}

void Widget::on_TargetSlot_3_clicked()
{
    targetSlot->theta = -45;
    targetSlot->update();
}

void Widget::on_TargetSlot_4_clicked()
{
  targetSlot->theta = 90;
  targetSlot->update();
}

void Widget::on_FreeSlot_2_clicked()
{
    FreeSlot *free  = new FreeSlot(45);
    scene->addItem(free);
}

void Widget::on_FreeSlot_3_clicked()
{
    FreeSlot *free  = new FreeSlot(-45);
    scene->addItem(free);
    cout<<"hi\n";
}

void Widget::on_FreeSlot_4_clicked()
{
    FreeSlot *free  = new FreeSlot(90);
    scene->addItem(free);
}

void Widget::on_BusySlot_2_clicked()
{
    OccupiedSlot *busy = new OccupiedSlot(45);
    scene->addItem(busy);

}

void Widget::on_BusySlot_3_clicked()
{
    OccupiedSlot *busy = new OccupiedSlot(-45);
    scene->addItem(busy);

}

void Widget::on_BusySlot_4_clicked()
{
    OccupiedSlot *busy = new OccupiedSlot(90);
    scene->addItem(busy);

}

void Widget::Run()
{
    double v = ui->v->toPlainText().toDouble();
    double phi = ui->phi->toPlainText().toDouble();
    double dt = ui->dt->toPlainText().toDouble();
    car->run(v, phi, dt);


}

void Widget::on_move_to_target_clicked()
{
    double targetX = targetSlot->x();
    double targetY = targetSlot->y();
    int dir = ui->moveToTarget->toPlainText().toInt();
    car->moveToTarget(targetX, targetY, dir);

}



