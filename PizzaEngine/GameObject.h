#pragma once

#include "Runnable.h";
#include "Drawable.h";
#include "Renderer.h";
#include <iostream>

class GameObject : public Runnable, public Drawable {
	public:
		GameObject();
		virtual void update();
		virtual void draw();
		float getX();
		float getY();
		float getWidth();
		float getHeight();
		void setX(float x);
		void setY(float y);
		void setWidth(float width);
		void setHeight(float height);
		unsigned int getColor();
	protected:
		float x, y, width, height;
		void fillRect();
		void setColor(unsigned int color);
		void setRect(float x, float y, float width, float height);
	private:
		unsigned int color;
};