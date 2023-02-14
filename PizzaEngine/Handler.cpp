#include "Handler.h"

Handler::Handler(Physical* engine) {
	objects = new GameObject*[1];
	fluids = new Fluid*[1];
	set = false;
	fset = false;
	this->engine = engine;
}

Handler::~Handler() {
	for (int i = 0; i < s; i++) {
		delete objects[i]; // Delete each GameObject in the array
	}
	delete[] objects; // Delete the objects array
}

void Handler::addObject(GameObject* object) {
	GameObject** newObjects;
	int newSize;
	if (set) {
		newObjects = new GameObject * [s + 1];
		s++;
		newSize = s;
	} else {
		newObjects = new GameObject * [1];
		set = true;
		newSize = 1;
	}

	for (int i = 0; i < newSize - 1; i++) {
		newObjects[i] = objects[i];
	}

	newObjects[newSize - 1] = object;

	Fluid* f = dynamic_cast<Fluid*>(object);

	if (f) {
		addFluid((Fluid*)object);
	}

	delete[] objects; // Delete the old array
	objects = newObjects; // Assign the new array to objects
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
	//std::cout << "X: " << Mouse::getX() << " Y: " << Mouse::getY() << "\n";
	for (int i = 0; i < s; i++) {
		objects[i]->handled.clear();
		objects[i]->updateVectors(engine, objects, s);
		if (fset) {
			for (int j = 0; j < fs; j++) {
				fluids[j]->updateDragged(objects[i]);
			}
		}
		objects[i]->update();
		objects[i]->updatePosition();
	}
}

void Handler::draw() {
	int count = 0;
	for (int i = 0; i < s; i++) {
		count++;
		objects[i]->draw();
	}
	//std::cout << count << " objects drawn\n";
}

void Handler::addFluid(Fluid* f) {
	Fluid** newFluids;
	int fnewSize;
	if (fset) {
		newFluids = new Fluid* [fs + 1];
		fs++;
		fnewSize = fs;
	} else {
		newFluids = new Fluid* [1];
		fset = true;
		fnewSize = 0;
	}

	for (int i = 0; i < fnewSize - 1; i++) {
		newFluids[i] = fluids[i];
	}

	newFluids[fs - 1] = f;

	delete[] fluids;
	fluids = newFluids;
}
