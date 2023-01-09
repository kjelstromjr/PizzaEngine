#include "Timer.h"

float Timer::time = 0;

float Timer::timeElapsed() {
	return Timer::time;
}

void Timer::setTimeElapsed(float time) {
	Timer::time = time;
}
