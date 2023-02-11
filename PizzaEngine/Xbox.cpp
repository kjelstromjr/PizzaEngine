#include "Xbox.h"

void remoteThread(float percent, int time) {
	XINPUT_VIBRATION vibration;
	ZeroMemory(&vibration, sizeof(XINPUT_VIBRATION));

	// Set the vibration values
	vibration.wLeftMotorSpeed = 65535 * (percent / 100);  // left motor full speed
	vibration.wRightMotorSpeed = 65535 * (percent / 100); // right motor full speed

	while (time > 0) {
		// Apply the vibration
		XInputSetState(0, &vibration);  // indicates which controller to send vibration to
		// wait for 5 sec
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		time--;
	}

	// Stop the vibration
	ZeroMemory(&vibration, sizeof(XINPUT_VIBRATION));
	XInputSetState(0, &vibration);
}

Xbox::Xbox() {
}

void Xbox::setVibration(float percent, int time) {
	std::thread t(std::bind(remoteThread, percent, time));
	t.detach();
}

bool Xbox::isA() {
	XINPUT_STATE state;
	DWORD result = XInputGetState(0, &state);
	if (result == ERROR_SUCCESS) {
		if (state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {
			return true;
		}
	}
	return false;
}

bool Xbox::isB() {
	XINPUT_STATE state;
	DWORD result = XInputGetState(0, &state);
	if (result == ERROR_SUCCESS) {
		if (state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {
			return true;
		}
	}
	return false;
}

bool Xbox::isX() {
	XINPUT_STATE state;
	DWORD result = XInputGetState(0, &state);
	if (result == ERROR_SUCCESS) {
		if (state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {
			return true;
		}
	}
	return false;
}

bool Xbox::isY() {
	XINPUT_STATE state;
	DWORD result = XInputGetState(0, &state);
	if (result == ERROR_SUCCESS) {
		if (state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {
			return true;
		}
	}
	return false;
}
