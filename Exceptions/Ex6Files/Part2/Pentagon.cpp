#include "Pentagon.h"
#include "MathUtils.h"
#include "ShapeException.h"
#include <iostream>

Pentagon::Pentagon(std::string nam, std::string col, double s)
    : Shape(nam, col)
{
    setSide(s);
}

void Pentagon::draw()
{
    std::cout << getName() << "\n" << getColor()
        << "\nSide: " << side
        << "\nArea: " << CalArea()
        << std::endl;
}

double Pentagon::CalArea()
{
    return MathUtils::CalPentagonArea(side);
}

void Pentagon::setSide(double s)
{
    if (s < 0)
        throw ShapeException();
    side = s;
}

double Pentagon::getSide()
{
    return side;
}
