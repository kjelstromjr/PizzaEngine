#pragma once

#ifndef HANDLER_H
#define HANDLER_H

#include <list>
#include "GameObject.h"
#include <iostream>
#include "Physical.h"
#include "Fluid.h"

class Handler {
	public:
		Handler(Physical* engine);
		~Handler();
		void addObject(GameObject* object);
		void removeObject(GameObject* object);
		GameObject* getObject(int i);
		int size();
		void update();
		void draw();

	private:
		GameObject** objects;
		Fluid** fluids;
		bool set;
		bool fset;
		int fs = 1;
		int s = 1;
		Physical* engine;
		void addFluid(Fluid* f);
};

#endif