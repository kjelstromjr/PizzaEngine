#include "GameObject.h"

GameObject::GameObject() {
	std::cout << "Created Object";
	x = 0;
	y = 0;
	width = 0;
	height = 0;
	color = 0x00;
}

void GameObject::update() {
}

void GameObject::draw() {
	Renderer::fillRect(10, 10, 10, 10, 0xff0000);
}

float GameObject::getX() {
	return x;
}

float GameObject::getY() {
	return y;
}

float GameObject::getWidth() {
	return width;
}

float GameObject::getHeight() {
	return height;
}

void GameObject::setX(float x) {
	this->x = x;
}

void GameObject::setY(float y) {
	this->y = y;
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
	Renderer::fillRect(x, y, width, height, color);
}

void GameObject::setColor(unsigned int color) {
	this->color = color;
}

void GameObject::setRect(float x, float y, float width, float height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}
