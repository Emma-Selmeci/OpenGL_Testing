#include "common.hpp"
#include "contextManager.hpp"
#include "shader.hpp"
#include "shaderProgram.hpp"
#include "vao.hpp"
#include "vbo.hpp"
#include "ebo.hpp"

#include <iostream>

struct Point {
    float x{rand() % 200 / 100.0f - 1.0f}, y{ rand() % 200 / 100.0f - 1.0f };
};

int main() { 

    Logger::init();

    WARN(LEVEL, "entered main()");
    //INFO(LEVEL, "this is a trace message " << t);
    CRITICAL(STARTUP, "this is a critical message");

    GLFWwindow* window = ContextManager::genContext();

    GLfloat vertexData[]{
        -0.5f,-0.5f,
        0.5f,-0.5f,
        -0.5f,0.5f,
        0.5f,0.5f,
    };

    GLuint elementData[]{
        0,1,2,
        1,3,2
    };

    VAO myVao;
    VBO myVbo;
    EBO myEbo;
    myVao.bind();
    myVbo.bind();
    myEbo.bind();
    debugcall(glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW));
    debugcall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elementData), elementData, GL_STATIC_DRAW));

    Shader s1{ "rectVShader.glsl" };
    Shader s2{ "rectFShader.glsl" };
    ShaderProgram program{ s1,s2 };
    program.use();

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    glPointSize(3.0f);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //Have a black clear color


    while (!glfwWindowShouldClose(window))
    {

        debugcall(glClear(GL_COLOR_BUFFER_BIT));
        debugcall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));
        
        glfwSwapBuffers(window);
        
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}