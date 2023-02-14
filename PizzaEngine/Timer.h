#pragma once
#ifndef TIMER_H
#define TIMER_H

class Timer {
	public:
		static float timeElapsed();
		static void setTimeElapsed(float time);

	private:
		static float time;
};

#endif