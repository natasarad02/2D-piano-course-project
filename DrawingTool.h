#ifndef DRAWING_TOOL_H
#define DRAWING_TOOL_H
#include "SoundMaker.h"
#include <GL/glew.h>   
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace SoundMaker;

namespace DrawingTool {
	void drawPianoFrame(unsigned int unifiedShader, unsigned texture);
	void drawWhiteKeys(int numWhiteKeys, unsigned int unifiedShader, unsigned texture);
	void drawBlackKeys(int numWhiteKeys, int numBlackKeys, unsigned int unifiedShader, unsigned texture);
	void showEmptySheet(int numWhiteKeys, int numBlackKeys, unsigned int unifiedShader, unsigned texture);	
	void writeOnSheet(int numWhiteKeys, int numBlackKeys, unsigned int unifiedShader, unsigned texture);
	void drawBackground(int numWhiteKeys, int numBlackKeys, unsigned int unifiedShader, unsigned texture);
	void drawVolume(int numWhiteKeys, int numBlackKeys, unsigned int unifiedShader, unsigned texture);
	void drawButton(int firstNum, int numWhiteKeys, int numBlackKeys, unsigned int unifiedShader, unsigned texture);
	void pressC(int numWhiteKeys, unsigned int unifiedShader, double xpos, GLFWwindow* window, unsigned texture, bool keyHandle, bool isPressed, char file1[], char file2[], char file3[]);
	void pressWhiteKey(int numWhiteKeys, unsigned int unifiedShader, double xpos, GLFWwindow* window, int num1, int num2, std::string filePath1, std::string filePath2, int key1, int key2, unsigned texture, bool keyHandle, bool isPressed);
	void pressBlackKey(int numWhiteKeys, unsigned int unifiedShader, double xpos, GLFWwindow* window, int num1, int num2, std::string filePath1, std::string filePath2, int key1, int key2, unsigned texture, bool keyHandle, bool isPressed);
	

}


#endif 
