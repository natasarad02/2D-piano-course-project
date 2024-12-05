#ifndef CURSOR_POSITIONS_H
#define CURSOR_POSITIONS_H
#include <GL/glew.h>   
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
namespace CursorPositions {

 
    bool cursorOnC(double xpos, double ypos);
    bool cursorOnWhiteKey(double xpos, double ypos, int widthParam, int offset1, int offset2);
    bool cursorOnBlackKey(double xpos, double ypos, int widthParam);
   


}


#endif // GLWF_FUNCTIONS_H