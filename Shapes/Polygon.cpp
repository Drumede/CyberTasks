#include "Polygon.h"

// Constructor
Polygon::Polygon(std::string type, std::string name) : Shape(name, type) {
	this->_points = std::vector<Point>();
}

// Destructor
Polygon::~Polygon() {
	for (int i = 0; i < this->_points.size(); i++) {
		this->_points.erase(this->_points.begin() + i);
	}
}

// Methods
double Polygon::getPerimeter() const {
	double perimeter = 0;
	int i = 0;
	for (i = 0; i < this->_points.size()-1; i++) {
		perimeter += this->_points[i].distance(this->_points[i + 1]);
	}
	perimeter += this->_points[i].distance(this->_points[0]);
	return perimeter;
}

double* Polygon::getLengths() const {
	double* lengths = new double[this->_points.size()];
	int i = 0;
	for (i = 0; i < this->_points.size() - 1; i++) {
		lengths[i] = this->_points[i].distance(this->_points[i + 1]);
	}
	lengths[i] = this->_points[i].distance(this->_points[0]);
	return lengths;
}

void Polygon::move(Point other) {
	for (int i = 0; i < this->_points.size(); i++) {
		this->_points[i] += other;
	}
}

// Getters
std::vector<Point> Polygon::getPoints() const {
	return this->_points;
}
