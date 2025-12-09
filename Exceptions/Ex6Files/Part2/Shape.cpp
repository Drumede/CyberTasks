#include "Shape.h"
#include <iostream>

int Shape::count = 0;

Shape::Shape(std::string nam, std::string col)
{
    name = nam;
    color = col;
    count++;
}

int Shape::getCount() {
    return count;
}

double Shape::CalArea() {
    std::cout << "Unknown area" << std::endl;
    return 0;
}

Shape::~Shape()
{
    count--;
}

void Shape::setName(std::string nam) {
    name = nam;
}
std::string Shape::getName() {
    return name;
}
void Shape::setColor(std::string col) {
    color = col;
}
std::string Shape::getColor() {
    return color;
}
