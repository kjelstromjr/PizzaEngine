#include "Pizza.h"
#include <iostream>

class Box : public GameObject, public Clickable {
	public:
		unsigned int color = ORANGE;
		Vector mouse;
		//float speed;
		//float velocity, acceleration;
		Box(int x, int y) {
			setRect(x, y, 50, 50);
			//speed = 0;
			//velocity = 0.0;
			//acceleration = 0.0001;
		}
		void update() {
			mouse.x = Mouse::getX() - Window::getWidth() / 2;
			mouse.y = Mouse::getY() - Window::getHeight() / 2;

			mouse.normalize();
			mouse *= 50;
			/*
			velocity += acceleration * Timer::timeElapsed();
			x += velocity * Timer::timeElapsed();
			if (x > Window::getWidth()) {
				x = 0;
			}
			*/
			/*
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

			if (isMouseOver()) {
				color = BLUE;
			} else {
				color = ORANGE;
			}
			*/
		}
		void draw() {
			setColor(color);
			//fillRect();
			Renderer::drawLine(Window::getWidth() / 2, Window::getHeight() / 2, mouse.x + (Window::getWidth() / 2), mouse.y + (Window::getHeight() / 2), color);
		}
		void onClick() {
			color = GREEN;
		}
};

int main() {
	Pizza* game = new Pizza(L"Hello there");
	game->showConsole();
	game->addObject(new Box(100, 100));
	game->setFPS(120);
	game->start();
}