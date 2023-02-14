#include "Water.h"

Water::Water(float x, float y, int width, int height, float c) : Fluid(x, y, width, height, c) {
	setRect(x, y, width, height);
}

void Water::update() {
}

void Water::draw() {
	setColor(BLUE);
	fillRect();
}
