#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "common.hpp"

class Texture {
	GLuint name;
	unsigned char* data; //Used to store actual image data
	int width, height, bpp;

public:
	Texture(const char* filePath);
	~Texture();

	void Bind(unsigned int slot = 0) const;
	void Unbind() const;

	inline int getWidth() const { return width; }
	inline int getHeight() const { return height; }
};

#endif //TEXTURE_HPP