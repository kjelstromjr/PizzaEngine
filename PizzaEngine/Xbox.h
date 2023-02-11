#pragma once

#include "Util.h"

#include <thread>
#include <functional>

class Xbox {
	public:
		Xbox();
		void setVibration(float percent, int time);
		bool isA();
		bool isB();
		bool isX();
		bool isY();
};