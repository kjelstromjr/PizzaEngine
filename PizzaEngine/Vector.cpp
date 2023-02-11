#include "Vector.h"
#include <iostream>

Vector::Vector() {
	this->x = 0.0;
	this->y = 0.0;
	this->l = -1;
}

Vector::Vector(float x, float y) {
	this->x = x;
	this->y = y;
	this->l = -1;
}

Vector::Vector(float x, float y, float l) {
	this->x = x;
	this->y = y;
	this->l = l;
}

float Vector::mag() {
	return sqrt(this->x * this->x + this->y * this->y);
}

void Vector::normalize() {
	float magnitude = mag();
	*this /= magnitude;
}

void Vector::limit(float n) {
	this->l = n;
}

float Vector::getLimit() {
	return this->l;
}

Vector Vector::operator+(const Vector &other) {
	return Vector(this->x + other.x, this->y + other.y, this->l);
}

Vector Vector::operator-(const Vector &other) {
	return Vector(this->x - other.x, this->y - other.y, this->l);
}

Vector Vector::operator*(const float other) {
	return Vector(this->x * other, this->y * other, this->l);
}

Vector Vector::operator/(const float other) {
	return Vector(this->x / other, this->y / other, this->l);
}

Vector& Vector::operator+=(const Vector& other) {
	*this = *this + other;
	return *this;
}

Vector& Vector::operator-=(const Vector& other) {
	*this = *this - other;
	return *this;
}

Vector& Vector::operator*=(const float other) {
	*this = *this * other;
	return *this;
}

Vector& Vector::operator/=(const float other) {
	*this = *this / other;
	return *this;
}
