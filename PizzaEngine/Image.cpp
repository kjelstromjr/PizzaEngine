#include "Image.h"

unsigned int* Image::loadImage(string fileName) {

}

void Image::clearCache() {
	delete[] Image::imageCache;
}
