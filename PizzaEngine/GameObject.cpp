#include "GameObject.h"

GameObject::GameObject() {
	std::cout << "Created Object";
	width = 0;
	height = 0;
	mass = 10;
	color = 0x00;
}

void GameObject::updatePosition() {
	float limit = acceleration.getLimit();
	if (limit != -1) {
		if (acceleration.x > limit) {
			acceleration.x = limit;
		}
		if (acceleration.y > limit) {
			acceleration.y = limit;
		}
	}

	velocity += acceleration * Timer::timeElapsed();

	limit = velocity.getLimit();
	if (limit != -1) {
		if (velocity.x > limit) {
			velocity.x = limit;
		}
		if (velocity.y > limit) {
			velocity.y = limit;
		}
	}
	position += velocity * Timer::timeElapsed();

	limit = position.getLimit();
	if (limit != -1) {
		if (position.x > limit) {
			position.x = limit;
		}
		if (position.y > limit) {
			position.y = limit;
		}
	}
}

void GameObject::update() {
}

void GameObject::updateVectors(Physical* engine) {
	this->acceleration *= 0;
	this->acceleration += engine->gravity;
}

void GameObject::draw() {
	Renderer::fillRect(10, 10, 10, 10, 0xff0000);
}

float GameObject::getX() {
	return position.x;
}

float GameObject::getY() {
	return position.y;
}

float GameObject::getWidth() {
	return width;
}

float GameObject::getHeight() {
	return height;
}

void GameObject::setX(float x) {
	position.x = x;
}

void GameObject::setY(float y) {
	position.y = y;
}

void GameObject::setWidth(float width) {
	this->width = width;
}

void GameObject::setHeight(float height) {
	this->height = height;
}

unsigned int GameObject::getColor() {
	return color;
}

void GameObject::setMass(float mass) {
	this->mass = mass;
}

float GameObject::getMass() {
	return mass;
}

void GameObject::applyForce(Vector force) {
	acceleration += force / mass;
}

bool GameObject::isIntersecting(GameObject* object) {
	return !(getX() > object->getX() + object->getWidth() || getX() + getWidth() < object->getX() || getY() > object->getY() + object->getHeight() || getY() + getHeight() < object->getY());
}

void GameObject::fillRect() {
	Renderer::fillRect(position.x, position.y, width, height, color);
}

void GameObject::setColor(unsigned int color) {
	this->color = color;
}

void GameObject::setRect(float x, float y, float width, float height) {
	position.x = x;
	position.y = y;
	this->width = width;
	this->height = height;
}

bool GameObject::isMouseOver() {
	int x = Mouse::getX();
	int y = Mouse::getY();
	if (x > position.x && x < position.x + this->width && y > position.y && y < position.y + this->height) {
		return true;
	} else {
		return false;
	}
}