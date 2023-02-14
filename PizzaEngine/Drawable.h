#pragma once
#ifndef DRAWABLE_H
#define DRAWABLE_H

class Drawable {
	public:
		bool drawing = true;
		virtual void draw() = 0;
};

#endif