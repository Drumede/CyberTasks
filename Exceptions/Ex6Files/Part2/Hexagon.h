#pragma once
#include "Shape.h"

class Hexagon : public Shape {
public:
    Hexagon(std::string, std::string, double);
    void draw() override;
    double CalArea() override;
    void setSide(double s);
    double getSide();
private:
    double side;
};
