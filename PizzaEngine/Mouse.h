#pragma once
class Mouse {
	public:
		static int getX();
		static int getY();
		static void setPos(int x, int y);

	private:
		static int x;
		static int y;
};