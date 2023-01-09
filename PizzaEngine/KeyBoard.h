#pragma once

#include "Buttons.h"
#include "Window.h"

class KeyBoard {
	public:
		static void processKey(unsigned int vk_code, bool is_down);
		static bool isDown(Button button);
		static bool isUp(Button button);
		static Input* getInput();
	private:
		static Input input;
};