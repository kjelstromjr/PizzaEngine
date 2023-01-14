#pragma once

#include "GameObject.h"

class Clickable {
	public:
		bool useClick(GameObject* object);
		virtual void onClick();
};