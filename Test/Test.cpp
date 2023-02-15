#include "Pizza.h"
#include <iostream>
#include "Physical.h"
#include "Water.h"

GameObject* other;

class Box : public GameObject, public Clickable {
	public:
		unsigned int color = WHITE;
		//Vector mouse;
		float speed;
		//float velocity, acceleration;
		Vector gravity = Vector(0, 0.1);

		Xbox* x = new Xbox();
		int vTime = 20;

		Box(int x, int y, int mass) {
			setRect(x, y, 50 + 0.1 * mass, 50 + 0.1 * mass);
			speed = 0;
			this->mass = mass;
			//velocity = 0.0;
			//acceleration = 0.0001;
		}
		void update() {
			applyForce(Vector(0.0001, 0));

			if (position.y + height >= Window::getHeight()) {
				velocity.y *= -1;
				position.y = Window::getHeight() - height;
				x->setVibration(100, vTime);
			}
			if (position.y <= 0) {
				velocity.y *= -1;
				position.y = 0;
				x->setVibration(100, vTime);
			}

			if (position.x <= 0) {
				velocity.x *= -1;
				position.x = 0;
				x->setVibration(100, vTime);
			}
			if (position.x + width >= Window::getWidth()) {
				velocity.x *= -1;
				position.x = Window::getWidth() - width;
				x->setVibration(100, vTime);
			}

			if (x->isA()) {
				color = GREEN;
			} else if (x->isB()) {
				color = RED;
			} else if (x->isY()) {
				color = YELLOW;
			} else if (x->isX()) {
				color = BLUE;
			} else {
				color = WHITE;
			}

			if (isIntersecting(other)) {
				color = ORANGE;
			} else {
				color = WHITE;
			}

			/*
			mouse.x = Mouse::getX() - Window::getWidth() / 2;
			mouse.y = Mouse::getY() - Window::getHeight() / 2;
			mouse.normalize();
			mouse *= 50;
			*/
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
				position.y -= speed;
			} else if (KeyBoard::isDown(DOWN)) {
				position.y += speed;
			}
			if (KeyBoard::isDown(LEFT)) {
				position.x -= speed;
			} else if (KeyBoard::isDown(RIGHT)) {
				position.x += speed;
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
			fillRect();
			
			//Renderer::drawLine(Window::getWidth() / 2, Window::getHeight() / 2, mouse.x + (Window::getWidth() / 2), mouse.y + (Window::getHeight() / 2), color);
		}
		void onClick() {
			color = ORANGE;
		}
};

int main() {
	/*
	XINPUT_STATE state;
	DWORD dwResult;

	// Check for controller connection
	if (XInputGetState(0, &state) == ERROR_SUCCESS) {
		// Input is being received from controller
		printf("Controller is connected\n");
	} else {
		printf("No controller connected\n");
		return 1;
	}

	XINPUT_VIBRATION vibration;
	ZeroMemory(&vibration, sizeof(XINPUT_VIBRATION));

	// Set the vibration values
	vibration.wLeftMotorSpeed = 65535;  // left motor full speed
	vibration.wRightMotorSpeed = 65535; // right motor full speed

	// Apply the vibration
	XInputSetState(0, &vibration);

	// wait for 5 sec
	Sleep(5000);

	// Stop the vibration
	ZeroMemory(&vibration, sizeof(XINPUT_VIBRATION));
	XInputSetState(0, &vibration);
	*/
	/*
	while (true) {
		// Get the current state of the controller
		dwResult = XInputGetState(0, &state);

		if (dwResult == ERROR_SUCCESS) {
			// Input is being received from controller
			float leftThumbX = state.Gamepad.sThumbLX;
			float leftThumbY = state.Gamepad.sThumbLY;

			// Do something with the input
			printf("Left thumbstick X: %f ", leftThumbX);
			printf("Left thumbstick Y: %f\n", leftThumbY);
		} else {
			printf("Error getting controller state\n");
		}
	}
	*/

	//Water* water = new Water(100, 100, 100, 100, 0.1);

	Pizza* engine = new Pizza(L"Hello there");

	Fluid* f = new Fluid(0, Window::getHeight() - 300, Window::getWidth(), Window::getHeight(), 0.1);
	f->stable = true;
	f->collidable = false;

	//engine->showConsole();
	//engine->addObject(f);
	engine->addObject(new Box(10, 100, 20));
	other = new Box(100, 100, 100);
	//engine->addObject(water);
	engine->addObject(other);
	engine->addObject(new Box(200, 200, 5));

	GameObject* object = new GameObject(300, 300, 10, 10);
	//engine->addObject(object);

	for (int i = 0; i < 100; i += 4) {
	}



	engine->game->gravity = Vector(0, 0.0001);
	//engine->setFPS(120);
	engine->start();
}