#include "Circle.h"
#include "ShapeException.h"
#include <iostream>

Circle::Circle(std::string nam, std::string col, double rad)
    : Shape(nam, col)
{
    setRad(rad); // validate early
}

void Circle::draw()
{
    std::cout << "\nColor is " << getColor()
        << "\nName is " << getName()
        << "\nradius is " << getRad()
        << "\nCircumference: " << CalCircumference() << std::endl;
}

void Circle::setRad(double rad)
{
    if (rad < 0)
        throw ShapeException();
    radius = rad;
}

double Circle::CalArea()
{
    return 3.14 * radius * radius;
}

double Circle::getRad()
{
    return radius;
}

double Circle::CalCircumference()
{
    return 2 * 3.14 * radius;
}
