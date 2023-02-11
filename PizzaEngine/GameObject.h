#pragma once

#include "Runnable.h"
#include "Drawable.h"
#include "Renderer.h"
#include "Mouse.h"
#include <iostream>
#include "Vector.h"
#include "Timer.h"
#include "Physical.h"

class GameObject : public Runnable, public Drawable {
	public:
		GameObject();
		void updatePosition();
		virtual void update();
		void updateVectors(Physical* engine);
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
		void setMass(float mass);
		float getMass();
		void applyForce(Vector force);
		Vector position;
		Vector velocity;
		Vector acceleration;
		bool isIntersecting(GameObject* object);
	protected:
		float width, height, mass;
		void fillRect();
		void setColor(unsigned int color);
		void setRect(float x, float y, float width, float height);
		bool isMouseOver();
	private:
		unsigned int color;
};