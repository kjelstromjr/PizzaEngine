#pragma once

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Runnable.h"
#include "Drawable.h"
#include "Renderer.h"
#include "Mouse.h"
#include <iostream>
#include "Vector.h"
#include "Timer.h"
#include "Physical.h"
#include <list>

class GameObject : public Runnable, public Drawable {
	public:
		GameObject();
		GameObject(float x, float y, int width, int height);
		void updatePosition();
		virtual void update();
		void updateVectors(Physical* engine, GameObject** objects, int size);
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
		bool stable;
		bool collidable;
		std::list<GameObject*> handled;
	protected:
		float width, height, mass;
		void fillRect();
		void setColor(unsigned int color);
		void setRect(float x, float y, float width, float height);
		bool isMouseOver();
	private:
		unsigned int color;
};

#endif