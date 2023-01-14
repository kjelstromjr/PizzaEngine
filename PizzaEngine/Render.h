#pragma once

#ifndef RENDER_H
#define RENDER_H

#include <windows.h>

typedef struct render_state {
	int height, width;
	void* memory;

	BITMAPINFO bitmap_info;
} Render_State;

#endif