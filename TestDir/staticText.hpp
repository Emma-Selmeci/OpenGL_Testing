#ifndef STATICTEXT_HPP
#define STATICTEXT_HPP

#include "common.hpp"

/*
* In order for this to work, we need a few things:
* A texture that holds the font image (yes, we're a little backwards in terms of technology)
* A dedicated buffer to store information: positions and texture coordinates
* A shader and a shaderprogram
*/

class StaticText {
	const char* text;
	void getCharOffsets(char c, float& x, float& y); //Helper function to calculate the x and y coords of every character in the texture map
	constexpr static float textureOffset = 1.0f / 16;
public:
	StaticText(const char*, float xPos, float yPos, float size);
	void render();
};

#endif //STATICTEXT_HPP