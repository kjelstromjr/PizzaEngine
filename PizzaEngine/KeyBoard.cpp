#include "KeyBoard.h"

Input KeyBoard::input = {};

void KeyBoard::processKey(unsigned int vk_code, bool is_down) {
	switch (vk_code) {
		case VK_UP: {
			KeyBoard::input.buttons[UP].isDown = is_down;
			KeyBoard::input.buttons[UP].changed = true;
		} break;
		case VK_DOWN: {
			KeyBoard::input.buttons[DOWN].isDown = is_down;
			KeyBoard::input.buttons[DOWN].changed = true;
		} break;
		case VK_LEFT: {
			KeyBoard::input.buttons[LEFT].isDown = is_down;
			KeyBoard::input.buttons[LEFT].changed = true;
		} break;
		case VK_RIGHT: {
			KeyBoard::input.buttons[RIGHT].isDown = is_down;
			KeyBoard::input.buttons[RIGHT].changed = true;
		} break;
	}
}

bool KeyBoard::isDown(Button button) {
	if (KeyBoard::input.buttons[button].isDown) {
		return true;
	} else {
		return false;
	}
}

bool KeyBoard::isUp(Button button) {
	return false;
}

Input* KeyBoard::getInput() {
	return &KeyBoard::input;
}
