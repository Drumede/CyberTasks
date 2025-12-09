#include "Quadrilateral.h"
#include "ShapeException.h"
#include <iostream>

Quadrilateral::Quadrilateral(std::string nam, std::string col, int h, int w)
    : Shape(nam, col)
{
    setHeight(h);
    setWidth(w);
}

void Quadrilateral::draw()
{
    std::cout << getName() << "\n" << getColor()
        << "\nWidth: " << width
        << "\nHeight: " << height
        << "\nArea: " << CalArea()
        << "\nPerimeter: " << getCalPerimater()
        << std::endl;
}

double Quadrilateral::CalArea()
{
    return width * height;
}

void Quadrilateral::setHeight(int h)
{
    if (h < 0) throw ShapeException();
    height = h;
}

void Quadrilateral::setWidth(int w)
{
    if (w < 0) throw ShapeException();
    width = w;
}

double Quadrilateral::CalPerimater()
{
    return 2 * (height + width);
}
double Quadrilateral::getCalPerimater()
{
    return 2 * (height + width);
}
int Quadrilateral::getHeight() { return height; }
int Quadrilateral::getWidth() { return width; }
