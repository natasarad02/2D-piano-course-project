#ifndef GLWF_FUNCTIONS_H
#define GLWF_FUNCTIONS_H

#include <GL/glew.h>   
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>


namespace GlfwFunctions {
    int startGlfwLibrary();
    int startGlewLibrary();
    GLFWwindow* createWindow();
    void createBackground();
    bool shouldClose(GLFWwindow* window);
    bool escapePressed(GLFWwindow* window);
    void closeWindow(GLFWwindow* window);
    void setUpScreen(GLFWwindow* window);
    bool CPressed(GLFWwindow* window, double xpos, double ypos);
    bool DPressed(GLFWwindow* window, double xpos, double ypos);
    bool EPressed(GLFWwindow* window, double xpos, double ypos);
    bool FPressed(GLFWwindow* window, double xpos, double ypos);
    bool GPressed(GLFWwindow* window, double xpos, double ypos);
    bool APressed(GLFWwindow* window, double xpos, double ypos);
    bool HPressed(GLFWwindow* window, double xpos, double ypos);

    bool CisPressed(GLFWwindow* window, double xpos, double ypos);
    bool DisPressed(GLFWwindow* window, double xpos, double ypos);
    bool FisPressed(GLFWwindow* window, double xpos, double ypos);
    bool GisPressed(GLFWwindow* window, double xpos, double ypos);
    bool AisPressed(GLFWwindow* window, double xpos, double ypos);

    bool leftArrow(GLFWwindow* window);
    bool rightArrow(GLFWwindow* window);

    bool recordPressed(GLFWwindow* window);
    bool stopPressed(GLFWwindow* window);



}


#endif // GLWF_FUNCTIONS_H