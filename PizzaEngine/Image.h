#pragma once

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