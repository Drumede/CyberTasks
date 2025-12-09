#pragma once
#include "Quadrilateral.h"

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(std::string, std::string, int, int, double, double);
    void draw() override;
    void setAngle(double, double);
    double getAngle();
    double getAngle2();
    double CalArea(double w, double h);
private:
    double angle;
    double angle2;
};
