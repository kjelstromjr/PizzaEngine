#include "Mouse.h"

int Mouse::x = 0;
int Mouse::y = 0;

int Mouse::getX() {
    return Mouse::x;
}

int Mouse::getY() {
    return Mouse::y;
}

void Mouse::setPos(int x, int y) {
    Mouse::x = x;
    Mouse::y = y;
}
