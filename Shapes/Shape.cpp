#include "Shape.h"

// Constructor
Shape::Shape(std::string name, std::string type) {
	this->_name = name;
	this->_type = type;
}

// Destructor
Shape::~Shape() {
	this->_name = "";
	this->_type = "";
}

// Getters
std::string Shape::getType() const {
	return this->_type;
}
std::string Shape::getName() const {
	return this->_name;
}

// Methods
double Shape::getArea() const {
	return 0;
}

double Shape::getPerimeter() const {
	return 0;
}

void Shape::move(Point other) {
	return;
}

void Shape::printDetails() {
	return;
}