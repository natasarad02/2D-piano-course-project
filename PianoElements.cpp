#include "PianoElements.h"

using namespace std;

namespace PianoElements {




    void addPianoSheet(vector<float>* vertices, float startX, float pianoWidth)
    {

        // Calculate the x-coordinates for the current key
        float xStart = startX; // x-coordinate of the left edge of the key
        float xEnd = xStart + pianoWidth;       // x-coordinate of the right edge of the key

        // Add the vertices for the current key (using the calculated xStart and xEnd)
        // Each key consists of two triangles (6 vertices)
        vertices->push_back(xStart); // x1
        vertices->push_back(0.6f);  // y1
        vertices->push_back(0.0f);   vertices->push_back(0.0f);  // u1, v1

      

        vertices->push_back(xStart); // x2
        vertices->push_back(0.92f);   // y2
        vertices->push_back(0.0f);   vertices->push_back(1.0f);  // u2, v2

        vertices->push_back(xEnd);   // x3
        vertices->push_back(0.6f);  // y3
        vertices->push_back(1.0f);   vertices->push_back(0.0f);  // u3, v3

        vertices->push_back(xStart); // x4
        vertices->push_back(0.92f);   // y4
        vertices->push_back(0.0f);   vertices->push_back(1.0f);  // u4, v4

        vertices->push_back(xEnd);   // x5
        vertices->push_back(0.92f);   // y5
        vertices->push_back(1.0f);   vertices->push_back(1.0f);  // u5, v5

        vertices->push_back(xEnd);   // x6
        vertices->push_back(0.6f);  // y6
        vertices->push_back(1.0f);   vertices->push_back(0.0f);  // u6, v6
       


    }


    void addVolume(vector<float>* vertices)
    {

        // Calculate the x-coordinates for the current key
        float xStart = 0.35; // x-coordinate of the left edge of the key
        float xEnd = xStart + 0.55;       // x-coordinate of the right edge of the key

        // Add the vertices for the current key (using the calculated xStart and xEnd)
        // Each key consists of two triangles (6 vertices)
        vertices->push_back(xStart); // x1
        vertices->push_back(0.6f);  // y1
        vertices->push_back(0.0f);   vertices->push_back(0.0f);  // u1, v1



        vertices->push_back(xStart); // x2
        vertices->push_back(0.92f);   // y2
        vertices->push_back(0.0f);   vertices->push_back(1.0f);  // u2, v2

        vertices->push_back(xEnd);   // x3
        vertices->push_back(0.6f);  // y3
        vertices->push_back(1.0f);   vertices->push_back(0.0f);  // u3, v3

        vertices->push_back(xStart); // x4
        vertices->push_back(0.92f);   // y4
        vertices->push_back(0.0f);   vertices->push_back(1.0f);  // u4, v4

        vertices->push_back(xEnd);   // x5
        vertices->push_back(0.92f);   // y5
        vertices->push_back(1.0f);   vertices->push_back(1.0f);  // u5, v5

        vertices->push_back(xEnd);   // x6
        vertices->push_back(0.6f);  // y6
        vertices->push_back(1.0f);   vertices->push_back(0.0f);  // u6, v6



    }


    void addBackground(vector<float>* vertices)
    {
        vertices->push_back(-1.0f); // x1
        vertices->push_back(1.0f);  // y1
        vertices->push_back(0.0f);  // u1 
        vertices->push_back(1.0f);  // v1 

        vertices->push_back(1.0f);  // x2
        vertices->push_back(1.0f);  // y2
        vertices->push_back(1.0f);  // u2 
        vertices->push_back(1.0f);  // v2 

        vertices->push_back(1.0f);  // x3
        vertices->push_back(-1.0f); // y3
        vertices->push_back(1.0f);  // u3 
        vertices->push_back(0.0f);  // v3 

        // Second triangle
        vertices->push_back(-1.0f); // x4
        vertices->push_back(1.0f);  // y4
        vertices->push_back(0.0f);  // u4 
        vertices->push_back(1.0f);  // v4 

        vertices->push_back(1.0f);  // x5
        vertices->push_back(-1.0f); // y5
        vertices->push_back(1.0f);  // u5 
        vertices->push_back(0.0f);  // v5 

        vertices->push_back(-1.0f); // x6
        vertices->push_back(-1.0f); // y6
        vertices->push_back(0.0f);  // u6 
        vertices->push_back(0.0f);  // v6 

    }
    void addPianoFrame(vector<float>* vertices, float startX, float pianoWidth)
    {

        // Calculate the x-coordinates for the current key
        float xStart = startX; // x-coordinate of the left edge of the key
        float xEnd = xStart + pianoWidth;       // x-coordinate of the right edge of the key

        // Add the vertices for the current key (using the calculated xStart and xEnd)
        // Each key consists of two triangles (6 vertices)
        vertices->push_back(xStart); // x1
        vertices->push_back(-0.6f);  // y1
        vertices->push_back(0.0f);   vertices->push_back(0.0f);  // u1, v1

        vertices->push_back(xStart); // x2
        vertices->push_back(1.0f);   // y2
        vertices->push_back(0.0f);   vertices->push_back(1.0f);  // u2, v2

        vertices->push_back(xEnd);   // x3
        vertices->push_back(-0.6f);  // y3
        vertices->push_back(1.0f);   vertices->push_back(0.0f);  // u3, v3

        vertices->push_back(xStart); // x4
        vertices->push_back(1.0f);   // y4
        vertices->push_back(0.0f);   vertices->push_back(1.0f);  // u4, v4


        vertices->push_back(xEnd);   // x5
        vertices->push_back(1.0f);   // y5
        vertices->push_back(1.0f);   vertices->push_back(1.0f);  // u5, v5

        vertices->push_back(xEnd);   // x6
        vertices->push_back(-0.6f);  // y6
        vertices->push_back(1.0f);   vertices->push_back(0.0f);  // u6, v6



    }

    void addBlackKey(vector<float>* vertices, float startX, float keyWidth)
    {

        // Calculate the x-coordinates for the current key
        float xStart = startX + keyWidth;               // x-coordinate of the left edge of the key
        float xEnd = xStart + keyWidth;      // x-coordinate of the right edge of the key

        // Add the vertices for the current key (2 triangles, 6 vertices)
        vertices->push_back(xStart); vertices->push_back(-0.1f); // x1, y1
        vertices->push_back(0.0f);   vertices->push_back(0.0f);  // u1, v1

        vertices->push_back(xStart); vertices->push_back(0.5f);  // x2, y2
        vertices->push_back(0.0f);   vertices->push_back(1.0f);  // u2, v2

        vertices->push_back(xEnd);   vertices->push_back(-0.1f); // x3, y3
        vertices->push_back(1.0f);   vertices->push_back(0.0f);  // u3, v3

        vertices->push_back(xStart); vertices->push_back(0.5f);  // x4, y4
        vertices->push_back(0.0f);   vertices->push_back(1.0f);  // u4, v4

        vertices->push_back(xEnd);   vertices->push_back(0.5f);  // x5, y5
        vertices->push_back(1.0f);   vertices->push_back(1.0f);  // u5, v5

        vertices->push_back(xEnd);   vertices->push_back(-0.1f); // x6, y6
        vertices->push_back(1.0f);   vertices->push_back(0.0f);  // u6, v6




    }

    void addWhiteKeys(vector<float>* vertices, int numWhiteKeys, float startX, float keyWidth)
    {


        for (int i = 0; i < numWhiteKeys; ++i) {
            // Calculate the x-coordinates for the current key
            float xStart = startX + i * keyWidth; // x-coordinate of the left edge of the key
            float xEnd = xStart + keyWidth;       // x-coordinate of the right edge of the key

            vertices->push_back(xStart); vertices->push_back(-0.5f); // x1, y1
            vertices->push_back(0.0f);   vertices->push_back(0.0f);  // u1, v1

            vertices->push_back(xStart); vertices->push_back(0.5f);  // x2, y2
            vertices->push_back(0.0f);   vertices->push_back(1.0f);  // u2, v2

            vertices->push_back(xEnd);   vertices->push_back(-0.5f); // x3, y3
            vertices->push_back(1.0f);   vertices->push_back(0.0f);  // u3, v3

            vertices->push_back(xStart); vertices->push_back(0.5f);  // x4, y4
            vertices->push_back(0.0f);   vertices->push_back(1.0f);  // u4, v4

            vertices->push_back(xEnd);   vertices->push_back(0.5f);  // x5, y5
            vertices->push_back(1.0f);   vertices->push_back(1.0f);  // u5, v5

            vertices->push_back(xEnd);   vertices->push_back(-0.5f); // x6, y6
            vertices->push_back(1.0f);   vertices->push_back(0.0f);  // u6, v6


        };

    }

    void addButton(vector<float>* vertices, float start)
    {
     
        float xStart = start; 
        float xEnd = xStart + 0.1;       
        vertices->push_back(xStart); // x1
        vertices->push_back(0.65f);  // y1
        vertices->push_back(0.0f);   vertices->push_back(0.0f);  // u1, v1



        vertices->push_back(xStart); // x2
        vertices->push_back(0.8f);   // y2
        vertices->push_back(0.0f);   vertices->push_back(1.0f);  // u2, v2

        vertices->push_back(xEnd);   // x3
        vertices->push_back(0.65f);  // y3
        vertices->push_back(1.0f);   vertices->push_back(0.0f);  // u3, v3

        vertices->push_back(xStart); // x4
        vertices->push_back(0.8f);   // y4
        vertices->push_back(0.0f);   vertices->push_back(1.0f);  // u4, v4

        vertices->push_back(xEnd);   // x5
        vertices->push_back(0.8f);   // y5
        vertices->push_back(1.0f);   vertices->push_back(1.0f);  // u5, v5

        vertices->push_back(xEnd);   // x6
        vertices->push_back(0.65f);  // y6
        vertices->push_back(1.0f);   vertices->push_back(0.0f);  // u6, v6
    }



}

