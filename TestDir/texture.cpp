#include "texture.hpp"

#include "..\ThirdParty\stb_image.h"

#include <iostream>

/*
* Doing the same shenanigans with shaders; full filepath and filename only are accepted as well :D
* Recommended read: https://en.wikipedia.org/wiki/Pixel
*/

Texture::Texture(const char* filePath) {

	//stbi_set_flip_vertically_on_load(1); //We'll se if this is needed lol

	if (strchr(filePath, '/') == nullptr) { //This is a full filepath (or is completely fucked up)
		std::string fName = "Res/Textures/";
		fName.append(filePath); //I'm not sure if this is the fastest way to append
		TRACE(STARTUP, "attempting to load texture with fname : " << fName);
		data = stbi_load(fName.c_str(), &width, &height, &bpp, 3);
	}
	else {
		TRACE(STARTUP, "attempting to load texture with fname : " << filePath);
		data = stbi_load(filePath, &width, &height, &bpp, 3);
	}

	if (data == nullptr) {
		const char* failLog = stbi_failure_reason();
		CRITICAL(STARTUP, "texture load failed, log :");
		CRITICAL(STARTUP, << failLog)
	}

	/*else {
		std::cout << "\nSuccesfully loaded data\n"; //temp
	}

	std::cout << '\n';
	std::cout << "Width : " << width << '\n';
	std::cout << "Height : " << height << '\n';

	for(int i = 0; i < 20; ++i) std::cout << (int) *(data++) << '\n';*/

	//If the data pointer is being manipulated, it will not be able to free!!!
	//Use a copy of data to manipulate image data

	glGenTextures(1, &name);
	debugcall(glBindTexture(GL_TEXTURE_2D, name));

	debugcall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
	debugcall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
	debugcall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER));
	debugcall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER));

	float color[] = { 1.0f, 0.0f, 1.0f, 1.0f };
	debugcall(glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color));

	//glTexImage2D(GL_TEXTURE_2D, 0, GL_R8, 3, 3, 0, GL_RED, GL_UNSIGNED_BYTE, textureData);

	debugcall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data));

	if (data) {
		stbi_image_free(data);
	}
}

Texture::~Texture()
{
	glDeleteTextures(1, &name);
}

void Texture::Bind(unsigned int slot) const
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, name);
}

void Texture::Unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
