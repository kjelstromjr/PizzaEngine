#pragma once

#include <list>
#include "GameObject.h"
#include <iostream>

class Handler {
	public:
		Handler();
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
};