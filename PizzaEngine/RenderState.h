#pragma once
#ifndef RENDERSTATE_H
#define RENDERSTATE_H

#include <windows.h>

class RenderState {
	public:
		int width, height;
		void* memory;
		BITMAPINFO bitmap_info;
		RenderState();
		~RenderState();
};

#endif