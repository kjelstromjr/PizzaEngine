#include "GameObject.h"

GameObject::GameObject() {
	std::cout << "Created Object\n";
	width = 0;
	height = 0;
	mass = 1;
	color = RED;
	stable = false;
	collidable = true;
}

GameObject::GameObject(float x, float y, int width, int height) {
	std::cout << "Created Object\n";
	this->position.x = x;
	this->position.y = y;
	this->width = width;
	this->height = height;
	this->color = RED;
	this->mass = 1;
	stable = false;
	collidable = true;
}

bool includes(std::list<GameObject*> list, GameObject* object) {
	for (GameObject* x : list) {
		if (x == object) {
			return true;
		}
	}
	return false;
}

void GameObject::updatePosition() {
	if (!stable) {
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
}

void GameObject::update() {
}

void GameObject::updateVectors(Physical* engine, GameObject** objects, int size) {
	if (!stable) {
		this->acceleration *= 0;
		this->acceleration += engine->gravity;
		if (collidable) {
			for (int i = 0; i < size; i++) {
				if (objects[i]->collidable && objects[i] != this) {
					int thisCenterX = this->position.x + this->width / 2;
					int thisCenterY = this->position.y + this->height / 2;
					int otherCenterX = objects[i]->position.x + objects[i]->width / 2;
					int otherCenterY = objects[i]->position.y + objects[i]->height / 2;

					if (isIntersecting(objects[i]) && !includes(objects[i]->handled, this)) {
						float totalMomentumx = this->mass * this->velocity.x + objects[i]->mass * objects[i]->velocity.x;

						float v1_fx = (totalMomentumx - (objects[i]->mass) * (this->velocity.x - objects[i]->velocity.x)) / (this->mass + objects[i]->mass);
						float v2_fx = (totalMomentumx - this->mass * (objects[i]->velocity.x - this->velocity.x)) / (this->mass + objects[i]->mass);

						float totalMomentumy = this->mass * this->velocity.y + objects[i]->mass * objects[i]->velocity.y;

						float v1_fy = (totalMomentumy - (objects[i]->mass) * (this->velocity.y - objects[i]->velocity.y)) / (this->mass + objects[i]->mass);
						float v2_fy = (totalMomentumy - this->mass * (objects[i]->velocity.y - this->velocity.y)) / (this->mass + objects[i]->mass);

						this->velocity = Vector(v1_fx, v1_fy);
						objects[i]->velocity = Vector(v2_fx, v2_fy);

						this->handled.push_back(objects[i]);
					}

					// rect1 = this
					// rect2 = other
					/*
					if (thisCenterX < otherCenterX) {
						// rect1 is to the left of rect2
						if (this->position.x + this->width > objects[i]->position.x && this->position.x + this->width < objects[i]->position.x + objects[i]->width) {
							// collision on the right side of rect1
							Vector temp = this->velocity.get();
							this->velocity = objects[i]->velocity;
							objects[i]->velocity = temp;
						}
					} else {
						// rect1 is to the right of rect2
						if (this->position.x < objects[i]->position.x + objects[i]->width && this->position.x > objects[i]->position.x) {
							// collision on the left side of rect1
						}
					}
					*/
					/*
					if (rect1.center.y < rect2.center.y) {
						// rect1 is above rect2
						if (rect1.bottom > rect2.top && rect1.bottom < rect2.bottom) {
							// collision on the bottom side of rect1
						}
					} else {
						// rect1 is below rect2
						if (rect1.top < rect2.bottom && rect1.top > rect2.top) {
							// collision on the top side of rect1
						}
					}
					*/
				}
			}
		}
	}
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