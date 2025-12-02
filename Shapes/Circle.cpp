#include "Circle.h"

// Constructor
Circle::Circle(Point center, double radius, std::string type, std::string name) : Shape(name,type) {
	if (radius <= 0) {
		std::cout << "Circle cannot have a radius of zero or less!" << std::endl;
		exit(1);
	}
	this->_center = center;
	this->_radius = radius;
}

// Destructor
Circle::~Circle() {
	this->_center.~Point();
	this->_radius = 0;
}

// Getters
Point Circle::getCenter() const {
	return this->_center;
}

double Circle::getRadius() const {
	return this->_radius;
}

double Circle::getArea() const {
	return PI * pow(this->_radius,2);
}

double Circle::getPerimeter() const {
	return 2 * PI * this->_radius;
}

void Circle::move(Point other) {
	this->_center += other;
}

void Circle::printDetails() {

}

void Circle::draw(const Canvas& canvas)
{
	canvas.draw_circle(getCenter(), getRadius());
}

void Circle::clearDraw(const Canvas& canvas)
{
	canvas.clear_circle(getCenter(), getRadius());
}


