#include "Fluid.h"

Fluid::Fluid(float x, float y, int width, int height, float c) : GameObject(x, y, width, height) {
	this->c = c;
}

void Fluid::update() {
	//std::cout << "X: " << position.x << " Y: " << position.y << "\n";
}

void Fluid::draw() {
	setColor(CYAN);
	fillRect();
}

float Fluid::getCoefficent() {
	return c;
}

void Fluid::setCoefficent(float c) {
	this->c = c;
}

void Fluid::updateDragged(GameObject* object) {
	if (isIntersecting(object) && object != this) {
		object->applyForce(calculateDrag(object));
	}
}

Vector Fluid::calculateDrag(GameObject* object) {
	// Magnitude is coefficient * speed squared
	float speed = object->velocity.mag();
	float dragMagnitude = this->c * speed * speed;
	
	// Direction is inverse of velocity
	Vector dragForce = object->velocity.get();
	dragForce *= -1;

	// Scale according to magnitude
	dragForce.normalize();
	dragForce *= dragMagnitude;

	return dragForce;
}
