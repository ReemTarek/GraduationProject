#ifndef CAR_H
#define CAR_H
#include<QGraphicsObject>
#include<QBrush>
#include<QPainter>
#include<cmath>
typedef long double ld;
class Car:public QGraphicsObject
{
    Q_OBJECT
public:
    Car();
   // void setPos(QPoint pos);
    QPointF getPos();
    void setTheta(double theta);//short int
    double getTheta();
   QPair<ld,ld> moveToTarget(double targetX, double targetY,int dir);
    void setWheelBase(double wheelBase);
    double getWheelBase();
    void setPhiMax(double phiMax);//short int
    double getPhiMax();
    // update bicycle state by incrementing it's postion in X-Axis and Y-Axis and incrementing it's theta
   // void update(double dx, double dy, double dtheta, double dt);
    // run the next dt seconds given current velocity and phi
    QPair<QPointF, double> run(double v, double phi, int dt);
    QRectF boundingRect() const;
    QColor getColor();
protected:
   // void timerEvent(QTimerEvent *event);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

private:
 //   int timerId;
   // int dt, iteration;// 3shan a3raf amta aw2f el timer
//    double dx, dy, dtheta;
    QBrush color;
    qreal wheelsAngle;
    QPointF pos; // current postion
    double theta; // the angle between the bicycle and X-Axis in radians
    double wheelBase; // distance between front wheels and rear wheels in meter
    short int phiMax; // maximum steer angle in radians
  //  double phi; //current steering angle
  //  double v; //current velocity
    const double PI = acos(-1);

};

#endif // CAR_H
