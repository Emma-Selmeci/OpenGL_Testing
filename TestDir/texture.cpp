#include "texture.hpp"

#include "ThirdParty/stb_image.h"

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
		data = stbi_load(fname.c_str(), &width, &height, &bpp, 4);
	}
	else {
		TRACE(STARTUP, "attempting to load texture with fname : " << filePath);
		data = stbi_load(filePath, &width, &height, &bpp, 4);
	}

	if (data == nullptr) {
		char* failLog = stbi_failure_reason();
		CRITICAL(STARTUP, "texture load failed, log :");
		CRITICAL(STARTUP, << failLog)
	}

	glGenTextures(1, &name);
	glBindTexture(GL_TEXTURE_2D, name);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	unsigned char textureData[] = {
		255,90,
		100,100,
		100,0
	};

	std::cout << sizeof(unsigned char);

	//glTexImage2D(GL_TEXTURE_2D, 0, GL_R8, 3, 3, 0, GL_RED, GL_UNSIGNED_BYTE, textureData);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_R8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer);
	glBindTexture(GL_TEXTURE_2D, 0);

	if (m_LocalBuffer) {
		stbi_image_free(m_LocalBuffer);
	}
}

Texture::~Texture()
{
	glDeleteTextures(1, &m_RendererID);
}

void Texture::Bind(unsigned int slot) const
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, m_RendererID);
}

void Texture::Unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
