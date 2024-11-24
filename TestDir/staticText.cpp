#include "staticText.hpp"
#include "contextManager.hpp"
#include "shader.hpp"
#include "shaderProgram.hpp"
#include "vao.hpp"
#include "vbo.hpp"
#include "ebo.hpp"
#include "texture.hpp"
#include <cstring>



void StaticText::getCharOffsets(char c, float& x, float& y) {
	y = c / 16 * textureOffset;
	x = c % 16 * textureOffset;
}

StaticText::StaticText(const char* str, float xPos, float yPos, float size) : text(str) {
	int sLength = strlen(str);

	GLFWwindow* window = ContextManager::genContext();

	//number of chars in string * number of vertices per char * (vertexCoords + textCoords)
	int vSize = sLength * 4 * (2 + 2);
	int eSize = sLength * 6;
	GLfloat* vertexData = new GLfloat[vSize];
	GLuint* eboData = new GLuint[eSize];

	GLfloat* vDataPointer = vertexData-1;
	GLuint* eboDataPointer = eboData - 1;
	for (int i = 0; i < sLength; ++i) {
		float xTex, yTex;
		float quadOffset = i * size;
		getCharOffsets(str[i], xTex, yTex);
		//bottom-left
		*++vDataPointer = xPos + quadOffset;
		*++vDataPointer = yPos - size;
		*++vDataPointer = xTex;
		*++vDataPointer = yTex + textureOffset;
		//bottom-right
		*++vDataPointer = xPos + size + quadOffset;
		*++vDataPointer = yPos - size;
		*++vDataPointer = xTex + textureOffset;
		*++vDataPointer = yTex + textureOffset;
		//top-left
		*++vDataPointer = xPos + quadOffset;
		*++vDataPointer = yPos;
		*++vDataPointer = xTex;
		*++vDataPointer = yTex;
		//top-right
		*++vDataPointer = xPos + size + quadOffset;
		*++vDataPointer = yPos;
		*++vDataPointer = xTex + textureOffset;
		*++vDataPointer = yTex;
		//Populating ebodata using a
		//0,1,2
		//1,3,2
		//format
		int eboCounter = i * 4;
		*++eboDataPointer = eboCounter; //0
		*++eboDataPointer = ++eboCounter; //1
		*++eboDataPointer = eboCounter + 1;
		*++eboDataPointer = eboCounter;
		*++eboDataPointer = ++eboCounter + 1; //2
		*++eboDataPointer = eboCounter;
	}



	VAO texVao;
	VBO texVbo;
	EBO texEbo;
	texVao.bind();
	texVbo.bind();
	texEbo.bind();
	debugcall(glBufferData(GL_ARRAY_BUFFER, vSize*sizeof(GLfloat), vertexData, GL_STATIC_DRAW));
	debugcall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, eSize*sizeof(GLuint), eboData, GL_STATIC_DRAW));

	delete[] vertexData;
	delete[] eboData;

	Shader s1{ "rectVShader.glsl" };
	Shader s2{ "rectFShader.glsl" };
	ShaderProgram program{ s1,s2 };
	program.use();

	Texture t{ "myfont.png" };
	//glUniform1i(glGetUniformLocation(program, "tex"), 0);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);

	while (!glfwWindowShouldClose(window))
	{

		debugcall(glClear(GL_COLOR_BUFFER_BIT));
		debugcall(glDrawElements(GL_TRIANGLES, 6*sLength, GL_UNSIGNED_INT, 0));

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	exit(0);
}
