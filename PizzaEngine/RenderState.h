#pragma once

#include <windows.h>

class RenderState {
	public:
		int width, height;
		void* memory;
		BITMAPINFO bitmap_info;
		RenderState();
		~RenderState();
};