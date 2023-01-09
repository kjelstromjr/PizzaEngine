#include "Pizza.h"
#include <iostream>

class Box : public GameObject {
	public:
		unsigned int color = 0xFFA500;
		float speed;
		float velocity, acceleration;
		Box(int x, int y) {
			setRect(x, y, 50, 50);
			speed = 0;
			velocity = 0.0;
			acceleration = 0.001;
		}
		void update() {
			/*
			velocity += acceleration;
			x += velocity;
			if (x > Window::getWidth()) {
				x = 0;
			}
			*/
			
			speed = 0.25 * Timer::timeElapsed();
			if (KeyBoard::isDown(UP)) {
				y -= speed;
			} else if (KeyBoard::isDown(DOWN)) {
				y += speed;
			}
			if (KeyBoard::isDown(LEFT)) {
				x -= speed;
			} else if (KeyBoard::isDown(RIGHT)) {
				x += speed;
			}
			
		}
		void draw() {
			setColor(color);
			fillRect();
		}
};

int main() {
	Pizza* game = new Pizza(L"Hello there");
	game->showConsole();
	game->addObject(new Box(100, 100));
	game->setFPS(120);
	game->start();
}