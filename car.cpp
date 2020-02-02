#include "car.h"
#include<cmath>
#include<iostream>
using namespace std;
typedef long double ld;
Car::Car(): color(Qt::gray), wheelsAngle(0)
{

   setScale(0.5);
   setFlag(QGraphicsItem::ItemIsMovable, true);
   setZValue(1);
   pos.rx() = 0;
   pos.ry() = 0;
   wheelBase = 32.5;
   phiMax = 30;
   theta = 0;
 //  iteration = 0;
}
QRectF Car::boundingRect() const
{
    return QRectF(-35, -81, 70, 115);
}



QColor Car::getColor()
{
    return color.color();
}
void Car::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    //setRotation(90);
    setPos(pos);
    setRotation(90+theta);
    painter->setBrush(Qt::green);
    painter->drawRect(-20, -58, 40, 2); // front axel
    painter->drawRect(-20, 7, 40, 2); // rear axel

    painter->setBrush(color);
    painter->drawRect(-25, -79, 50, 10); // front wing

    painter->drawEllipse(-25, -48, 50, 20); // side pods
    painter->drawRect(-25, -38, 50, 35); // side pods
    painter->drawRect(-5, 9, 10, 10); // back pod

    painter->drawEllipse(-10, -81, 20, 100); // main body

    painter->drawRect(-17, 19, 34, 15); // rear wing

    painter->setBrush(Qt::black);
    painter->drawPie(-5, -51, 10, 15, 0, 180 * 16);
    painter->drawRect(-5, -44, 10, 10); // cocpit

    painter->save();
    painter->translate(-20, -58);
    painter->rotate(wheelsAngle);
    painter->drawRect(-10, -7, 10, 15); // front left
    painter->restore();

    painter->save();
    painter->translate(20, -58);
    painter->rotate(wheelsAngle);
    painter->drawRect(0, -7, 10, 15); // front left
    painter->restore();

    painter->drawRect(-30, 0, 12, 17); // rear left
    painter->drawRect(19, 0, 12, 17);  // rear right
}
/*void Car::setPos(QPoint pos) {
    this->pos = pos;
}*/
QPointF Car::getPos() {
    return pos;
}

void Car::setTheta(double theta) {
    this->theta = theta;
}

double Car::getTheta() {
    return theta;
}

QPair<ld,ld> Car::moveToTarget(double xtarget, double ytarget, int dir)
{

   ld x0, y0,  t=10;
   x0=pos.rx(), y0 = pos.ry();
   ld thetaRad = theta*PI / 180;
   ld x = xtarget - x0,  y = ytarget - y0, v = hypot(x, y)/t*dir;

    ld b = sin(thetaRad), a = cos(thetaRad), c = v*b, d = v * a, e = v * b - y;
    ld A = (e*e + (x-d)*(x-d)), B = 2*e*d+2*c*(x-d), C = d*d-v*v+c*c;
    if(B*B < 4*A*C){
        cout << "NO";
        return{-1, -1};
    }else{

        ld alphaPos = (-B+sqrt(B*B-4*A*C)) / (2*A);
        ld alphaNeg = (-B-sqrt(B*B-4*A*C)) / (2*A);
        ld g = thetaRad+alphaPos*(t-1);
        ld xp=v/alphaPos*sin(g)-v/alphaPos*sin(thetaRad)+v*cos(thetaRad);
        ld yp = -v/alphaPos*cos(g)+v/alphaPos*cos(thetaRad)+v*sin(thetaRad);
        ld phi=atan(alphaPos*wheelBase/v)*180/PI;
        cout <<alphaPos*180/PI<<" "<< xp << " " << yp << endl;
        cout << phi;
      //  if(fabs(xp-x)<=5 && fabs(yp-y)<=5)
        run(v, phi, t);
        return {v, phi};
    }

}

void Car::setWheelBase(double wheelBase) {
    this->wheelBase = wheelBase;
}

double Car::getWheelBase() {
    return wheelBase;
}

void Car::setPhiMax(double phiMax) {
    this->phiMax = phiMax;
}

double Car::getPhiMax() {
    return phiMax;
}

/*void Car::update(double dx, double dy, double dtheta, double dt) {
    pos.rx() += dx * dt * 1000;
    pos.ry() += dy * dt * 1000;
    theta += dtheta * dt;

}*/
/*void Car::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
    if(iteration == dt){

        iteration = 0;
        killTimer(timerId);

    }else{
         double thetaInRadian = theta * PI / 180;
    dx = v * cos(thetaInRadian);
    dy = v * sin(thetaInRadian);
    pos.rx() += dx ;
    pos.ry() += dy ;
    theta += dtheta;
    ++iteration;
     cout << pos.ry() <<" " <<dtheta<<endl;
    update();
  }

}*/
QPair<QPointF, double> Car::run(double v, double phi, int dt) {
    if (phi > phiMax)
        phi = phiMax;
    if (phi < -phiMax)
        phi = -phiMax;
     wheelsAngle = phi;
     double phiInRadian = phi * PI / 180; 
     double dtheta = v / (wheelBase) * tan(phiInRadian) * 180 / PI;
     ld thetaRad = theta*PI/180;
     ld dthetaRad = dtheta*PI/180,dx,dy;
     if(dtheta==0)
         dx = v*cos(thetaRad)*dt, dy = v * sin(thetaRad)*dt;
     else{
      dx = v/dthetaRad*sin(thetaRad+dthetaRad*(dt-1))-v/dthetaRad*sin(thetaRad)+v*cos(thetaRad);
      dy = -v/dthetaRad*cos(thetaRad+dthetaRad*(dt-1))+v/dthetaRad*cos(thetaRad)+v*sin(thetaRad);
     }

     pos.rx()+=dx;
     pos.ry()+=dy;
     theta+=dtheta*dt;
     update();
     //timerId = startTimer(1000/33);
     return {pos, theta};//need to be fixed
}
