#pragma once
#ifndef RUNNABLE_H
#define RUNNABLE_H

class Runnable {
	public:
		bool running = true;
		virtual void update() = 0;
};

#endif