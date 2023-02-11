#include "Handler.h"

Handler::Handler(Physical* engine) {
	objects = new GameObject*[1];
	set = false;
	this->engine = engine;
}

void Handler::addObject(GameObject* object) {
	GameObject** newObjects;
	int newSize;
	if (set) {
		newObjects = new GameObject*[s + 1];
		s++;
		newSize = s;
	} else {
		newObjects = new GameObject*[0];
		set = true;
		newSize = 1;
	}

	for (int i = 0; i < newSize - 1; i++) {
		newObjects[i] = objects[i];
	}

	newObjects[s - 1] = object;

	objects = newObjects;
}

void Handler::removeObject(GameObject* object) {
}

GameObject* Handler::getObject(int i) {
	return objects[i];
}

int Handler::size() {
	return s;
}

void Handler::update() {
	for (int i = 0; i < s; i++) {
		objects[i]->updateVectors(engine);
		objects[i]->update();
		objects[i]->updatePosition();
	}
}

void Handler::draw() {
	for (int i = 0; i < s; i++) {
		objects[i]->draw();
	}
}
