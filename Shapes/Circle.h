#pragma once

#include "Shape.h"
#include "Point.h"

#define PI 3.14

class Circle : public Shape
{
public:

	// Constructor
	Circle(Point center, double radius, std::string type, std::string name);

	// Destructor
	~Circle();

	// Getters
	Point getCenter() const;
	double getRadius() const;

	// Methods
	double getArea() const override;
	double getPerimeter() const override;

	void move(Point other) override;
	void printDetails() override;

	void draw(const Canvas& canvas) override;
	void clearDraw(const Canvas& canvas) override;
private:
	Point _center;
	double _radius;
};