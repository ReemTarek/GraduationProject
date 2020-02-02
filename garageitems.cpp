#include "garageitems.h"

GarageItems::GarageItems()
{
    setFlag(ItemIsMovable, true);
}

QRectF GarageItems::boundingRect() const
{
        return QRectF(-35, -81, 70, 115);


}

QColor GarageItems::getColor()
{return color;

}
