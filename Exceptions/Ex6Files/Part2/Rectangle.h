#pragma once
#include "Quadrilateral.h"

class rectangle : public Quadrilateral {
public:
    rectangle(std::string, std::string, int, int);
    void draw() override;
    double CalArea(double, double);
    bool isSquare(int, int);
};
