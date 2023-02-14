#pragma once
#ifndef CLICKABLE_H
#define CLICKABLE_H

#include "GameObject.h"

class Clickable {
	public:
		bool useClick(GameObject* object);
		virtual void onClick();
};

#endif