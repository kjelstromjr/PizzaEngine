#pragma once

#include "Fluid.h"

class Water : public Fluid {
	public:
		Water(float x, float y, int width, int height, float c);
		void update();
		void draw();
};

