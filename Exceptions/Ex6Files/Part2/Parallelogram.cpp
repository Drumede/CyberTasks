#include "Parallelogram.h"
#include "ShapeException.h"
#include <iostream>
#include <cmath>

Parallelogram::Parallelogram(std::string nam, std::string col, int h, int w, double ang, double ang2)
    : Quadrilateral(nam, col, h, w)
{
    setAngle(ang, ang2);
}

void Parallelogram::draw()
{
    std::cout << getName() << "\n" << getColor()
        << "\nHeight: " << getHeight()
        << "\nWidth: " << getWidth()
        << "\nAngles: " << angle << ", " << angle2
        << "\nArea: " << CalArea(getWidth(), getHeight())
        << std::endl;
}

double Parallelogram::CalArea(double w, double h)
{
    return w * h;
}

void Parallelogram::setAngle(double ang, double ang2)
{
    if (!std::isfinite(ang) || !std::isfinite(ang2))
        throw ShapeException();
    angle = ang;
    angle2 = ang2;
}

double Parallelogram::getAngle() { return angle; }
double Parallelogram::getAngle2() { return angle2; }
