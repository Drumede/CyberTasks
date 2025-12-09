#pragma once
#include "Shape.h"

class Pentagon : public Shape {
public:
    Pentagon(std::string, std::string, double);
    void draw() override;
    double CalArea() override;
    void setSide(double s);
    double getSide();
private:
    double side;
};
