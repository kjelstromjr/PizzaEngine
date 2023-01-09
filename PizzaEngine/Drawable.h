#pragma once
class Drawable {
	public:
		bool drawing = true;
		virtual void draw() = 0;
};