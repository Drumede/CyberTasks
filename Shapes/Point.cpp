#include "Point.h"

// Constructors
Point::Point() {
	this->_x = 0;
	this->_y = 0;
}
Point::Point(double x, double y) {
	this->_x = x;
	this->_y = y;
}

// Destructor
Point::~Point() {
	this->_x = 0;
	this->_y = 0;
}

// Operators
Point Point::operator+(const Point& other) const {
	Point newPoint = Point(this->_x, this->_y);

	newPoint._x += other._x;
	newPoint._y += other._y;

	return newPoint;
}

Point& Point::operator+=(const Point& other) {
	this->_x += other._x;
	this->_y += other._y;

	return *this;
}

bool Point::operator==(const Point& other) {

	return this->_x == other._x && this->_y == other._y;
}

// Getters
double Point::getX() const {
	return this->_x;
}

double Point::getY() const {
	return this->_y;
}

// Methods
double Point::distance(const Point& other) const {
	double distx = other._x - this->_x;
	double disty = other._y - this->_y;
	return sqrt(pow(distx,2) + pow(disty,2));
}