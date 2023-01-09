#pragma once
class Runnable {
	public:
		bool running = true;
		virtual void update() = 0;
};