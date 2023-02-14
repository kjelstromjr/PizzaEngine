#pragma once
#ifndef RENDERER_H
#define RENDERER_H

#include "Render.h";
#include <cmath>

#define WHITE		0xFFFFFF
#define BLACK		0x00
#define GRAY		0x808080
#define LIGHT_GRAY	0xD3D3D3
#define RED			0xFF0000
#define ORANGE		0xFFA500
#define YELLOW		0xFFFF00
#define GREEN		0x00FF00
#define CYAN		0x00FFFF
#define BLUE		0x0000FF
#define PURPLE		0xFF00FF

class Renderer {
	public:
		static void setRenderState(Render_State state);
		static void renderBackground();
		static void clearScreen(unsigned int color);
		static void drawPixel(int x, int y, unsigned int color);
		static void fillRectInPixels(int x0, int y0, int x1, int y1, unsigned int color);
		static void fillRect(int x, int y, int width, int height, unsigned int color);
		static void drawLine(int x1, int y1, int x2, int y2, unsigned int color);

	private:
		static Render_State render_state;
};

#endif