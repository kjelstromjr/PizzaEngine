#include "Vector.h"

Vector::Vector() {
	this->x = 0.0;
	this->y = 0.0;
}

Vector::Vector(float x, float y) {
	this->x = x;
	this->y = y;
}

float Vector::mag() {
	return sqrt(this->x * this->x + this->y * this->y);
}

void Vector::normalize() {
	float magnitude = mag();
	*this /= magnitude;
}

Vector Vector::operator+(const Vector &other) {
	return Vector(this->x + other.x, this->y + other.y);
}

Vector Vector::operator-(const Vector &other) {
	return Vector(this->x - other.x, this->y - other.y);
}

Vector Vector::operator*(const float other) {
	return Vector(this->x * other, this->y * other);
}

Vector Vector::operator/(const float other) {
	return Vector(this->x / other, this->y / other);
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
