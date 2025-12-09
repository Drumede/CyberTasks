#pragma once
#include <string>

class Shape
{
public:
    virtual void draw() = 0;
    virtual double CalArea();
    static int getCount();
    void setName(std::string);
    std::string getName();
    void setColor(std::string);
    std::string getColor();
    Shape(std::string, std::string);
    ~Shape();
private:
    static int count;
    std::string name;
    std::string color;
};
