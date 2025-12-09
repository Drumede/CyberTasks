#include "Rectangle.h"
#include "ShapeException.h"
#include <iostream>

rectangle::rectangle(std::string nam, std::string col, int w, int h): Quadrilateral(nam, col, h, w) {
}

void rectangle::draw()
{
    std::cout << getName() << "\n" << getColor()
        << "\nHeight: " << getHeight()
        << "\nWidth: " << getWidth()
        << "\nArea: " << CalArea(getWidth(), getHeight())
        << "\nis square (1=true,0=false): "
        << isSquare(getWidth(), getHeight())
        << std::endl;
}

double rectangle::CalArea(double w, double h)
{
    return w * h;
}

bool rectangle::isSquare(int w, int h)
{
    return (w == h);
}
