#pragma once

class Timer {
	public:
		static float timeElapsed();
		static void setTimeElapsed(float time);

	private:
		static float time;
};