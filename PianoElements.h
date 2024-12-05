#ifndef PIANO_ELEMENTS_H
#define PIANO_ELEMENTS_H
#include <GL/glew.h>   
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
namespace PianoElements {

	void addBackground(vector<float>* vertices);
	
	void addButton(vector<float>* vertices, float start);
	
	void addVolume(vector<float>* vertices);
	void addPianoSheet(vector<float>* vertices, float startX, float pianoWidth);
	void addPianoFrame(vector<float>* vertices, float startX, float pianoWidth);
	void addBlackKey(vector<float>* vertices, float startX, float keyWidth);
	void addWhiteKeys(vector<float>* vertices, int numWhiteKeys, float startX, float keyWidth);
	//static unsigned loadImageToTexture(const char* filePath);

}

#endif // GLWF_FUNCTIONS_H
