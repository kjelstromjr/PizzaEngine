#pragma once

#include <cmath>

struct Vector {
	float x;
	float y;
	Vector();
	Vector(float x, float y);

	float mag();
	void normalize();

	Vector operator+(const Vector& other);
	Vector operator-(const Vector& other);
	Vector operator*(const float other);
	Vector operator/(const float other);

	Vector& operator+=(const Vector& other);
	Vector& operator-=(const Vector& other);
	Vector& operator*=(const float other);
	Vector& operator/=(const float other);
};