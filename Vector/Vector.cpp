#include "Vector.h"

Vector::Vector(int n) {
	if (n < 2)
		n = 2;
	this->_elements = new int[n];
	this->_capacity = n;
	this->_size = 0;
	this->_resizeFactor = n;
}

Vector::~Vector() {
	delete this->_elements;
}

int Vector::size() const{
	return this->_size;
}

int Vector::capacity() const {
	return this->_capacity;
}

int Vector::resizeFactor() const {
	return this->_resizeFactor;
}

bool Vector::empty() const {
	return _size == 0 ? true : false;
}

void Vector::push_back(const int& val) {
	if (this->_size == this->_capacity) {
		int newCapacity = this->_capacity + this->_resizeFactor;
		int* newElements = new int[newCapacity];

		for (int i = 0; i < this->_capacity; i++) {
			newElements[i] = this->_elements[i];
		}

		delete[] this->_elements;

		this->_elements = newElements;
		this->_capacity = newCapacity;
	}
	this->_elements[this->_size] = val;
	this->_size++;
}

int Vector::pop_back() {
	if (this->empty())
	{
		std::cout << "error: pop from empty vector" << std::endl;
		return -9999;
	}
	int lastElement = this->_elements[this->_size - 1];
	this->_elements[this->_size - 1] = NULL;
	this->_size--;
	return lastElement;
}

void Vector::reserve(const int n) {
	int newCapacity = ceil((float)n / this->_resizeFactor) * this->_resizeFactor;
	if (newCapacity < this->_capacity)
		return;
	int* newElements = new int[newCapacity];

	for (int i = 0; i < this->_capacity; i++) {
		newElements[i] = this->_elements[i];
	}

	delete[] this->_elements;

	this->_elements = newElements;
	this->_capacity = newCapacity;
}

void Vector::resize(const int n) {
	if (n > this->_capacity)
		this->reserve(n);
	int oldSize = this->_size;
	std::cout << oldSize << std::endl;
	this->_size = n;
	std::cout << oldSize << std::endl;
	for (int i = 0; i < oldSize; i++) {
		if (n > oldSize && i > oldSize) this->_elements[i] = 0;
		if (n < oldSize && i > oldSize) this->_elements[i] = NULL;
	}
}

void Vector::assign(int val) {
	for (int i = 0; i < this->_size; i++) {
		this->_elements[i] = val;
	}
}

void Vector::resize(int n, const int& val) {
	if (n > this->_capacity)
		this->reserve(n);
	int oldSize = this->_size;
	this->_size = n;
	for (int i = 0; i < n; i++) {
		if (n > oldSize && i >= oldSize) this->_elements[i] = val;
		if (n < oldSize && i >= oldSize) this->_elements[i] = NULL;
	}
}

Vector::Vector(const Vector& other) {
	this->_elements = new int[other.capacity()];
	this->_capacity = other.capacity();
	this->_size = other.size();
	this->_resizeFactor = other.resizeFactor();

	for (int i = 0; i < other.size(); i++) {
		this->_elements[i] = other[i];
	}
}

Vector& Vector::operator=(const Vector& other) {
	delete[] this->_elements;
	this->_elements = new int[other.capacity()];
	this->_capacity = other.capacity();
	this->_size = other.size();
	this->_resizeFactor = other.resizeFactor();

	for (int i = 0; i < other.size(); i++) {
		this->_elements[i] = other[i];
	}
	
	return *this;
}

int& Vector::operator[](int n) const {
	if (n > this->_size-1 || n < 0) {
		std::cerr << "Wanted index is out of bounds!" << std::endl;
		return this->_elements[0];
	}
	return this->_elements[n];
}

Vector Vector::operator+(const Vector& other) const {
	Vector newVector = Vector(*this);

	for (int i = 0; i < newVector.size(); i++) {
		newVector._elements[i] += other[i];
	}

	return newVector;
}

Vector Vector::operator-(const Vector& other) const {
	Vector newVector = Vector(*this);

	for (int i = 0; i < newVector.size(); i++) {
		newVector._elements[i] -= other[i];
	}

	return newVector;
}

Vector& Vector::operator+=(const Vector& other) {
	for (int i = 0; i < this->_size; i++) {
		this->_elements[i] += other[i];
	}

	return *this;
}

Vector& Vector::operator-=(const Vector& other) {
	for (int i = 0; i < this->_size; i++) {
		this->_elements[i] -= other[i];
	}

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Vector& v) {
	os << "Vector Info:\nCapacity is " << v.capacity() << "\nSize is " << v.size() << "\ndata is {";

	for (int i = 0; i < v.size(); i++) {
		os << v[i];
		if (i + 1 < v.size()) os << ",";
	}
	os << "}\n";
	return os;
}