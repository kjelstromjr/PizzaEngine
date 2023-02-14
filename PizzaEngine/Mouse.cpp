#include "Mouse.h"
#include <iostream>

int Mouse::x = 0;
int Mouse::y = 0;

int Mouse::getX() {
    //std::cout << "X: " << Mouse::x << " Y: " << Mouse::y << "\n";
    return Mouse::x;
}

int Mouse::getY() {
    return Mouse::y;
}

void Mouse::setPos(int x, int y) {
    Mouse::x = x;
    Mouse::y = y;
}
