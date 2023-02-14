#pragma once
#ifndef BUTTONS_H
#define BUTTONS_H

struct ButtonState {
	bool isDown;
	bool changed;
};

enum Button {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	GAMEPAD_A,
	COUNT
};

struct Input {
	ButtonState buttons[COUNT];
};

#endif