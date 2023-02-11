#pragma once

#include <list>
#include "GameObject.h"
#include <iostream>
#include "Physical.h"

class Handler {
	public:
		Handler(Physical* engine);
		void addObject(GameObject* object);
		void removeObject(GameObject* object);
		GameObject* getObject(int i);
		int size();
		void update();
		void draw();

	private:
		GameObject** objects;
		bool set;
		int s = 1;
		Physical* engine;
};