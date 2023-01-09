#include "Pizza.h"

Pizza::Pizza(LPCWSTR title) {
	h = new Handler();
	w = new Window(title, h);
	w->hideConsole();
}

Pizza::Pizza(LPCWSTR title, bool fullscreen) {
	h = new Handler();
	w = new Window(title, fullscreen, h);
	w->hideConsole();
}

Pizza::Pizza(LPCWSTR title, int width, int height) {
	h = new Handler();
	w = new Window(title, width, height, h);
	w->hideConsole();
}

Pizza::Pizza(LPCWSTR title, int width, int height, bool fullscreen) {
	h = new Handler();
	w = new Window(title, width, height, fullscreen, h);
	w->hideConsole();
}

void Pizza::start() {
	w->start();
}

void Pizza::addObject(GameObject* object) {
	h->addObject(object);
}

void Pizza::showConsole() {
	w->showConsole();
}

void Pizza::setFPS(int fps) {
	w->setFPS(fps);
}

int Pizza::getFPS() {
	return w->getFPS();
}
