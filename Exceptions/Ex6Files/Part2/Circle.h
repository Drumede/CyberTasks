#pragma once
#include "Shape.h"

class Circle : public Shape {
public:
    Circle(std::string, std::string, double);
    void draw() override;
    double CalArea() override;
    double CalCircumference();
    void setRad(double rad);
    double getRad();
private:
    double radius;
};
