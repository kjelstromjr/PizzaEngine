#pragma once

#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <map>
using namespace std;

class Image {
	public:
		static unsigned int* loadImage(string fileName);
		static void clearCache();

	private:
		static map<string, unsigned int*> map;
};

#endif