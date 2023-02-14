#pragma once
#ifndef MOUSE_H
#define MOUSE_H

class Mouse {
	public:
		static int getX();
		static int getY();
		static void setPos(int x, int y);

	private:
		static int x;
		static int y;
};

#endif