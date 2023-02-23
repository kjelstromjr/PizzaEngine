#pragma once

#ifndef IMAGE_H
#define IMAGE_H

#ifndef EXCLUDE_CODE
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#endif

#include <string>
#include <map>
using namespace std;

#include "BufferedImage.h"

class ImageLoader {
	public:
		static void loadImage(string fileName);
		static unsigned char* getImage(string fileName);
		static BufferedImage* bufferImage(string fileName);
		static void clearCache();

	private:
		static map<string, unsigned char*> map;
};

#endif