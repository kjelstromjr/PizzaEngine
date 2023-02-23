#include "ImageLoader.h"

map<string, unsigned char*> ImageLoader::map;

void ImageLoader::loadImage(string fileName) {
	int width, height, channels;
	unsigned char* image = stbi_load(fileName.c_str(), &width, &height, &channels, STBI_rgb_alpha);
	map[fileName] = image;
}

unsigned char* ImageLoader::getImage(string fileName) {
	if (map[fileName] == nullptr) {
		loadImage(fileName);
	}

	return map[fileName];
}

BufferedImage* ImageLoader::bufferImage(string fileName) {
	int width, height, channels;
	unsigned char* image = stbi_load(fileName.c_str(), &width, &height, &channels, STBI_rgb_alpha);
	map[fileName] = image;
	return new BufferedImage(image, width, height, channels);
}

void ImageLoader::clearCache() {
	std::map<std::string, unsigned char*>::iterator it = map.begin();

	// Iterate through the map and print the elements
	while (it != map.end()) {
		unsigned char* image = it->second;
		stbi_image_free(image);
		++it;
	}
	map.clear();
}
