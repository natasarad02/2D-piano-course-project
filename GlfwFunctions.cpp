#define _CRT_SECURE_NO_WARNINGS

#include "GlfwFunctions.h"
#include "ShaderFunctions.h"
#include "CursorPositions.h"

using namespace CursorPositions;
using namespace std;

//float width = 1920;
//float height = 1080;

namespace GlfwFunctions {

	int startGlfwLibrary()
	{
		if (!glfwInit())
		{
			cout << "GLFW library is not loaded\n" << endl;
			return 1;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

	int startGlewLibrary()
	{
		if (glewInit() != GLEW_OK)
		{
			std::cout << "GLEW library is not loaded\n";
			return 3;
		}
	}


	GLFWwindow* createWindow()
	{
		GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
		if (!primaryMonitor)
		{
			cerr << "Failed to get primary monitor" << endl;
			glfwTerminate();
			return NULL;
		}

		const GLFWvidmode* videoMode = glfwGetVideoMode(primaryMonitor);
		if (!videoMode) {
			std::cerr << "Failed to get video mode" << std::endl;
			glfwTerminate();
			return NULL;
		}


		GLFWwindow* window = glfwCreateWindow(
			videoMode->width,  
			videoMode->height,        
			"Piano",
			primaryMonitor,           
			NULL
		);

		if (window == NULL)
		{
			cout << "Window is not created" << endl;
			glfwTerminate();
			return NULL;
		}

		glfwMakeContextCurrent(window);
		return window;


	}

	void createBackground()
	{
		glClearColor(82.0f / 255.0f, 4.0f / 255.0f, 4.0f / 255.0f, 1.0f);
	}

	bool shouldClose(GLFWwindow* window)
	{
		return glfwWindowShouldClose(window);
	}

	bool escapePressed(GLFWwindow* window)
	{
		return glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS;
	}


	double convertX(double xpos, GLFWwindow* window)
	{
		int width, height;
		glfwGetWindowSize(window, &width, &height);

		return (2.0 * xpos / width) - 1.0;

	}

	double convertY(double ypos, GLFWwindow* window)
	{
		int width, height;
		glfwGetWindowSize(window, &width, &height);
		return 1.0 - (2.0 * ypos / height);
	}

	// ****** NOTA C ****** //

	bool CPressed(GLFWwindow* window, double xpos, double ypos)
	{
		xpos = convertX(xpos, window);
		ypos = convertY(ypos, window);
		return glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS || (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS && cursorOnC(xpos, ypos));
	}


	// ****** NOTA C# ****** //

	bool CisPressed(GLFWwindow* window, double xpos, double ypos)
	{
		xpos = convertX(xpos, window);
		ypos = convertY(ypos, window);
		return glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS || (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS && cursorOnBlackKey(xpos, ypos, 0));
	}


	// ****** NOTA D ****** //

	bool DPressed(GLFWwindow* window, double xpos, double ypos)
	{
		xpos = convertX(xpos, window);
		ypos = convertY(ypos, window);

		return glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS || (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS && cursorOnWhiteKey(xpos, ypos, 1, 1, 1));
	}

	// ****** NOTA D# ****** //

	bool DisPressed(GLFWwindow* window, double xpos, double ypos)
	{
		xpos = convertX(xpos, window);
		ypos = convertY(ypos, window);
		return glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS || (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS && cursorOnBlackKey(xpos, ypos, 1));
	}


	// ****** NOTA E ****** //

	bool EPressed(GLFWwindow* window, double xpos, double ypos)
	{
		xpos = convertX(xpos, window);
		ypos = convertY(ypos, window);


		return glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS || (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS && cursorOnWhiteKey(xpos, ypos, 2, 1, 2));
	}



	// ****** NOTA F ****** //

	bool FPressed(GLFWwindow* window, double xpos, double ypos)
	{
		xpos = convertX(xpos, window);
		ypos = convertY(ypos, window);

		return glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS || (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS && cursorOnWhiteKey(xpos, ypos, 3, 0, 1));
	}

	// ****** NOTA F# ****** //

	bool FisPressed(GLFWwindow* window, double xpos, double ypos)
	{
		xpos = convertX(xpos, window);
		ypos = convertY(ypos, window);
		return glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_8) == GLFW_PRESS || (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS && cursorOnBlackKey(xpos, ypos, 3));
	}



	// ****** NOTA G ****** //

	bool GPressed(GLFWwindow* window, double xpos, double ypos)
	{
		xpos = convertX(xpos, window);
		ypos = convertY(ypos, window);

		return glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS || (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS && cursorOnWhiteKey(xpos, ypos, 4, 1, 1));
	}

	// ****** NOTA G# ****** //

	bool GisPressed(GLFWwindow* window, double xpos, double ypos)
	{
		xpos = convertX(xpos, window);
		ypos = convertY(ypos, window);
		return glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_9) == GLFW_PRESS || (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS && cursorOnBlackKey(xpos, ypos, 4));
	}


	// ****** NOTA A ****** //

	bool APressed(GLFWwindow* window, double xpos, double ypos)
	{
		xpos = convertX(xpos, window);
		ypos = convertY(ypos, window);

		return glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS || (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS && cursorOnWhiteKey(xpos, ypos, 5, 1, 1));
	}

	// ****** NOTA A# ****** //

	bool AisPressed(GLFWwindow* window, double xpos, double ypos)
	{
		xpos = convertX(xpos, window);
		ypos = convertY(ypos, window);
		return glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS || (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS && cursorOnBlackKey(xpos, ypos, 5));
	}


	// ****** NOTA H ****** //

	bool HPressed(GLFWwindow* window, double xpos, double ypos)
	{
		xpos = convertX(xpos, window);
		ypos = convertY(ypos, window);

		return glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS || (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS && cursorOnWhiteKey(xpos, ypos, 6, 1, 2));
	}

	bool leftArrow(GLFWwindow* window)
	{
		return glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS;
	}

	bool rightArrow(GLFWwindow* window)
	{
		return glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS;
	}


	void closeWindow(GLFWwindow* window)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
	void setUpScreen(GLFWwindow* window) {


		//Zamjena vidljivog bafera sa pozadinskim
		glfwSwapBuffers(window);

		//Hvatanje dogadjaja koji se ticu okvira prozora (promjena velicine, pomjeranje itd)
		glfwPollEvents();
	}


	bool recordPressed(GLFWwindow* window)
	{
		return glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS;
	}

	bool stopPressed(GLFWwindow* window)
	{
		return glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS;
	}




}