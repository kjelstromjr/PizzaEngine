#include "GameObject.h"

GameObject::GameObject() {
	std::cout << "Created Object";
	width = 0;
	height = 0;
	color = 0x00;
}

void GameObject::updatePosition() {
	velocity += acceleration * Timer::timeElapsed();
	position += velocity * Timer::timeElapsed();
}

void GameObject::update() {
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