#include "Clickable.h"

bool Clickable::useClick(GameObject* object) {
    if (Mouse::getX() >= object->getX() && Mouse::getX() <= object->getX() + object->getWidth() && Mouse::getY() >= object->getY() && Mouse::getY() <= object->getY() + object->getHeight()) {
        onClick();
        return true;
    }
    return false;
}

void Clickable::onClick() {
}