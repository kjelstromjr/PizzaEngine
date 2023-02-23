#pragma once
#include <iostream>

class BufferedImage {
	public:
		BufferedImage(unsigned char* buffer, int width, int height, int channels);
		unsigned int getColor(int x, int y);
		int getWidth();
		int getHeight();
	private:
		unsigned char* buffer;
		int width, height, channels;
		unsigned char alpha;
};