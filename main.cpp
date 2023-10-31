#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window); 

int main(void)
{
    // Initializing GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Setting up forward compatibility
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Creating a window obj
    GLint WIDTH = 800, HEIGHT = 600;
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGLSandbox", NULL, NULL);

    if (window == NULL) {
        std::cout<<"Failed to create GLFW window"<<std::endl;
        glfwTerminate();
        return -1;
    }

    // Setting main context to the window obj
    glfwMakeContextCurrent(window);

    // Initializing GLAD Loader
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }   

    // Setting the viewport
    glViewport(0, 0, WIDTH, HEIGHT);

    // Setting the frame buffer callback
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Event loop
    while(!glfwWindowShouldClose(window)) {
        // processing inputs
        processInput(window);
        
        glfwSwapBuffers(window);
        glfwPollEvents();    
    }  

    glfwTerminate();
  
    return 0;
}

// Framebuffer callback
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}  

// Process Input function
void processInput(GLFWwindow* window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) 
        glfwSetWindowShouldClose(window, true);
}