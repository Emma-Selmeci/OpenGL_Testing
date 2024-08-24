#include "common.hpp"
#include "contextManager.hpp"

int main() {
    
    TRACE(Main method entered);

    GLFWwindow* window = ContextManager::genContext();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        debugcall(glClear(GL_COLOR_BUFFER_BIT));

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}