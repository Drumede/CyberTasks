#include "Hexagon.h"
#include "MathUtils.h"
#include "ShapeException.h"
#include <iostream>

Hexagon::Hexagon(std::string nam, std::string col, double s)
    : Shape(nam, col)
{
    setSide(s);
}

void Hexagon::draw()
{
    std::cout << getName() << "\n" << getColor()
        << "\nSide: " << side
        << "\nArea: " << CalArea()
        << std::endl;
}

double Hexagon::CalArea()
{
    return MathUtils::CalHexagonArea(side);
}

void Hexagon::setSide(double s)
{
    if (s < 0)
        throw ShapeException();
    side = s;
}

double Hexagon::getSide()
{
    return side;
}
