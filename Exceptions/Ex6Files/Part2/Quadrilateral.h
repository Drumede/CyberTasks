#pragma once

#include "Shape.h"

class Quadrilateral : public Shape {
public:
    Quadrilateral(std::string, std::string, int, int);
    void draw() override;
    double CalArea() override;
    double CalPerimater();
    double getCalPerimater();
    void setHeight(int h);
    void setWidth(int w);
    int getHeight();
    int getWidth();
private:
    int width;
    int height;
};
