#pragma once
#ifndef FLUID_H
#define FLUID_H

#include "GameObject.h"

class Fluid : public GameObject {
	public:
		Fluid(float x, float y, int width, int height, float c);
		void update();
		void draw();
		float getCoefficent();
		void setCoefficent(float c);
		void updateDragged(GameObject* object);
		Vector calculateDrag(GameObject* object);

	private:
		float c;
};

#endif