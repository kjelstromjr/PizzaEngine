#include "BufferedImage.h"

BufferedImage::BufferedImage(unsigned char* buffer, int width, int height, int channels) {
	this->buffer = buffer;
	this->width = width;
	this->height = height;
	this->channels = channels;
}

unsigned int BufferedImage::getColor(int x, int y) {
	unsigned char* pixel_ptr = buffer + (y * width + x) * channels;
	if (channels == 4) {
		alpha = pixel_ptr[3];
	}
	unsigned char red = pixel_ptr[0];
	unsigned char green = pixel_ptr[1];
	unsigned char blue = pixel_ptr[2];
	unsigned int color = ((unsigned int)red << 16) | ((unsigned int)green << 8) | (unsigned int)blue;
	return color;
}

int BufferedImage::getWidth() {
	return width;
}

int BufferedImage::getHeight() {
	return height;
}
