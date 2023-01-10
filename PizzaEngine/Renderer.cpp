#include "Renderer.h"
#include <iostream>

Render_State Renderer::render_state;

void Renderer::setRenderState(Render_State state) {
	render_state = state;
}

void Renderer::renderBackground() {
	unsigned int* pixel = (unsigned int*)render_state.memory;
	for (int y = 0; y < render_state.height; y++) {
		for (int x = 0; x < render_state.width; x++) {
			*pixel++ = x * y;
		}
	}
}

void Renderer::clearScreen(unsigned int color) {
	
	unsigned int* pixel = (unsigned int*)render_state.memory;
	for (int y = 0; y < render_state.height; y++) {
		for (int x = 0; x < render_state.width; x++) {
			*pixel++ = color;
		}
	}
	
	//memset((unsigned int*)render_state.memory, color, render_state.width * render_state.height);
}

void Renderer::drawPixel(int x, int y, unsigned int color) {
	if (x >= 0 && x < render_state.width && y >= 0 && y < render_state.height) {
		__try {
			unsigned int* pixel = (unsigned int*)render_state.memory;
			y = render_state.height - y;
			pixel += y * render_state.width + x;
			*pixel = color;
		} __except (EXCEPTION_EXECUTE_HANDLER) {
			//std::cout << x << " " << y << std::endl;
		}
	}
}

void Renderer::fillRectInPixels(int x0, int y0, int x1, int y1, unsigned int color) {
	for (int y = y0; y < y1; y++) {
		for (int x = x0; x < x1; x++) {
			drawPixel(x, y, color);
		}
	}
}

void Renderer::fillRect(int x, int y, int width, int height, unsigned int color) {
	fillRectInPixels(x, y, x + width, y + height, color);
}

void Renderer::drawLine(int x1, int y1, int x2, int y2, unsigned int color) {

}