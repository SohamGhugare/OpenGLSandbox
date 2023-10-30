//
//  main.cpp
//  OpenGLSandbox
//
//  Created by Soham Ghugare on 30/10/23.
//

#include <iostream>

//// GLEW
//#define GLEW_STATIC
//#include <GL/glew.h>

// GLAD
#include <glad/glad.h>

// GLFW
#include <GLFW/glfw3.h>

int main() {
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
    
    if (window==NULL) {
        std::cout<<"Failed to create GLFW window"<<std::endl;
        glfwTerminate();
        return -1;
    }
    
    // Setting main context to the window obj
    glfwMakeContextCurrent(window);
    
}
