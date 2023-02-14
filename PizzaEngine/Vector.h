#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>

struct Vector {
	float x;
	float y;
	Vector();
	Vector(float x, float y);
	Vector(float x, float y, float l);

	Vector get();

	float mag();
	void normalize();
	void limit(float n);
	float getLimit();

	Vector operator+(const Vector& other);
	Vector operator-(const Vector& other);
	Vector operator*(const float other);
	Vector operator/(const float other);

	Vector& operator+=(const Vector& other);
	Vector& operator-=(const Vector& other);
	Vector& operator*=(const float other);
	Vector& operator/=(const float other);

	private:
		float l;
};

#endif