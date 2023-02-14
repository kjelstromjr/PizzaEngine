#pragma once
#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include "Window.h"
#include "Util.h"
#include "Xbox.h"
#include "Physical.h"

using namespace std;

class Pizza {
	public:
		Pizza(LPCWSTR title);
		Pizza(LPCWSTR title, bool fullscreen);
		Pizza(LPCWSTR title, int width, int height);
		Pizza(LPCWSTR title, int width, int height, bool fullscreen);
		void start();
		void addObject(GameObject* object);
		void showConsole();
		void setFPS(int fps);
		int getFPS();
		Physical* game;

	private:
		Window* w;
		Handler* h;
};

#endif