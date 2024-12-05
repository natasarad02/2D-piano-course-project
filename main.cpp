#include "GlfwFunctions.h"
#include "ShaderFunctions.h"
#include "PianoElements.h"
#include "TextureFunctions.h"
#include "DrawingTool.h"
#include "SoundMaker.h"

#include <thread> // For std::this_thread::sleep_for
#include <chrono> // For std::chrono::duration
#include <vector>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace std;
using namespace SoundMaker;


using namespace GlfwFunctions;
using namespace ShaderFunctions;
using namespace PianoElements;
using namespace TextureFunctions;
using namespace DrawingTool;
using namespace SoundMaker;
//unsigned int compileShader(GLenum type, const char* source); //Uzima kod u fajlu na putanji "source", kompajlira ga i vraca sejder tipa "type"
//unsigned int createShader(const char* vsSource, const char* fsSource); //Pravi objedinjeni sejder program koji se sastoji od Verteks sejdera ciji je kod na putanji vsSource i Fragment sejdera na putanji fsSource


static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{

    int windowWidth, windowHeight;
    glfwGetWindowSize(window, &windowWidth, &windowHeight);

    xpos = (2.0 * xpos / windowWidth) - 1.0;
    ypos = 1.0 - (2.0 * ypos / windowHeight);
    // Output the percentages (for debugging purposes)
  //  std::cout << "Cursor Position: " << xpos << ", " << ypos << std::endl;
    
}

bool isEHandled = false;
bool isWHandled = false;
bool isSpaceHandled = false;
bool isFirstSet = false;
bool isSecondSet = false;
bool isViolin = false;

double convertX(GLFWwindow* window, double xpos)
{
    int windowWidth, windowHeight;
    glfwGetWindowSize(window, &windowWidth, &windowHeight);
    return (2.0 * xpos / windowWidth) - 1.0;
}

double convertY(GLFWwindow* window, double ypos)
{
    int windowWidth, windowHeight;
    glfwGetWindowSize(window, &windowWidth, &windowHeight);
    return 1.0 - (2.0 * ypos / windowHeight);
}

bool violinPressed(GLFWwindow* window, double xpos, double ypos)
{
    int state = glfwGetKey(window, GLFW_KEY_3);
    xpos = convertX(window, xpos);
    ypos = convertY(window, ypos);

    if (state == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS || (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS && xpos <= -0.355 && xpos >= -0.455 && ypos <= 0.8 && ypos >= 0.65)) {
        isViolin = true;
        return true;
    }
    else if (state == GLFW_RELEASE) {
        isViolin = false;  // Reset when released
    }
    return false;
}
bool firstSetPressed(GLFWwindow* window, double xpos, double ypos)
{
    int state = glfwGetKey(window, GLFW_KEY_1);
    xpos = convertX(window, xpos);
    ypos = convertY(window, ypos);
    if (state == GLFW_PRESS || (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS && xpos <= -0.555 && xpos >= -0.655 && ypos <= 0.8 && ypos >= 0.65)) {
        isFirstSet = true;
        return true;
    }
    else if (state == GLFW_RELEASE) {
        isFirstSet = false;  // Reset when released
    }
    return false;
}

bool secondSetPressed(GLFWwindow* window, double xpos, double ypos)
{
    int state = glfwGetKey(window, GLFW_KEY_2);
    xpos = convertX(window, xpos);
    ypos = convertY(window, ypos);
    if (state == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS || (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS && xpos <= -0.455 && xpos >= -0.555 && ypos <= 0.8 && ypos >= 0.65)) {
        isSecondSet = true;
        return true;
    }
    else if (state == GLFW_RELEASE) {
        isSecondSet = false;  // Reset when released
    }
    return false;
}


bool spacePressed(GLFWwindow* window, double xpos, double ypos)
{
    int state = glfwGetKey(window, GLFW_KEY_SPACE);
    xpos = convertX(window, xpos);
    ypos = convertY(window, ypos);
    if (state == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS || (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS && xpos <= -0.655 && xpos >= -0.755 && ypos <= 0.8 && ypos >= 0.65)) {
        isSpaceHandled = true;
        return true;
    }
    else if (state == GLFW_RELEASE) {
        isSpaceHandled = false;  // Reset when released
    }
    return false;
}
bool stopPressedMain(GLFWwindow* window, double xpos, double ypos) {
    int state = glfwGetKey(window, GLFW_KEY_E);
    xpos = convertX(window, xpos);
    ypos = convertY(window, ypos);
    if ((state == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS || (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS && xpos <= -0.755 && xpos >= -0.855 && ypos <= 0.8 && ypos >= 0.65)) && !isEHandled) {
        isEHandled = true;
        isWHandled = false;// Mark E as handled
        return true;
    }
    else if (state == GLFW_RELEASE) {
        isEHandled = false;  // Reset when released
    }
    return false;
}
bool recordPressedMain(GLFWwindow* window, double xpos, double ypos) {
    int state = glfwGetKey(window, GLFW_KEY_W);
    xpos = convertX(window, xpos);
    ypos = convertY(window, ypos);
    if ((state == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS || (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS && xpos <= -0.855 && xpos >= -0.955 && ypos <= 0.8 && ypos >= 0.65)) && !isEHandled) {
        
        isWHandled = true;
        isEHandled = false;// Mark E as handled
        return true;
    }
    else if (state == GLFW_RELEASE) {
        isWHandled = false;  // Reset when released
    }
    return false;
}


bool isWPressed = false; 
bool isEPressed = false;


void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    // Handle the W key
    

    if (key == GLFW_KEY_E) {
        if (action == GLFW_PRESS && !isEPressed) {
            isEPressed = true;
            std::cout << "E key pressed" << std::endl;

            // Place your action here
        }
        else if (action == GLFW_RELEASE) {
            isEPressed = false;
            std::cout << "E key released" << std::endl;
        }
    }
}


static unsigned loadImageToTexture(const char* filePath) {
    int TextureWidth;
    int TextureHeight;
    int TextureChannels;
    unsigned char* ImageData = stbi_load(filePath, &TextureWidth, &TextureHeight, &TextureChannels, 0);
    if (ImageData != NULL)
    {
        //Slike se osnovno ucitavaju naopako pa se moraju ispraviti da budu uspravne
        stbi__vertical_flip(ImageData, TextureWidth, TextureHeight, TextureChannels);

        // Provjerava koji je format boja ucitane slike
        GLint InternalFormat = -1;
        switch (TextureChannels) {
        case 1: InternalFormat = GL_RED; break;
        case 2: InternalFormat = GL_RG; break;
        case 3: InternalFormat = GL_RGB; break;
        case 4: InternalFormat = GL_RGBA; break;
        default: InternalFormat = GL_RGB; break;
        }
      
        unsigned int Texture;
        glGenTextures(1, &Texture);
        glBindTexture(GL_TEXTURE_2D, Texture);
        glTexImage2D(GL_TEXTURE_2D, 0, InternalFormat, TextureWidth, TextureHeight, 0, InternalFormat, GL_UNSIGNED_BYTE, ImageData);
        glBindTexture(GL_TEXTURE_2D, 0);
        // oslobadjanje memorije zauzete sa stbi_load posto vise nije potrebna
        stbi_image_free(ImageData);
        return Texture;
    }
    else
    {
        std::cout << "Textura nije ucitana! Putanja texture: " << filePath << std::endl;
        std::cout << stbi_failure_reason() << std::endl;
        if (std::ifstream(filePath)) {
            std::cout << "File exists and is readable: " << filePath << std::endl;
        }
        else {
            std::cerr << "File not found or cannot be read: " << filePath << std::endl;
        }

        stbi_image_free(ImageData);
        return 0;
    }
}




bool isScroll = false;

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    if (yoffset < 0) {
        VolumeDown(); 
    }
    else if (yoffset > 0) {
        VolumeUp();  
    }

    isScroll = true;

}

void createCustomCursor(GLFWwindow* window)
{
    int width, height, channels;

    unsigned char* imageData = stbi_load("res/smallNote.png", &width, &height, &channels, STBI_rgb_alpha);
    if (!imageData) {
        std::cerr << "Failed to load cursor image: " << "res/cursorNoteResized.png" << std::endl;
        return;
    }

    cout << "SIRINA " << width << endl;
    cout << "VISINA " << height << endl;
    GLFWimage cursorImage;
    cursorImage.width = width;
    cursorImage.height = height;
    cursorImage.pixels = imageData;

    GLFWcursor* customCursor = glfwCreateCursor(&cursorImage, 0, 0); // (0, 0) is the hotspot
    if (customCursor) {
        glfwSetCursor(window, customCursor);
        std::cout << "Custom cursor set successfully!" << std::endl;
    }
    else {
        std::cerr << "Failed to create custom cursor." << std::endl;
    }

    stbi_image_free(imageData);
}
int main(void)
{

    // ++++++++++++++++++++++++++++++++++++++++++++++++++++++ INICIJALIZACIJA ++++++++++++++++++++++++++++++++++++++++++++++++++++++

    // Pokretanje GLFW biblioteke
    startGlfwLibrary();

    //Stvaranje prozora
    GLFWwindow* window = createWindow();
    if (window == NULL)
    {
        return 2;
    }

    // Inicijalizacija GLEW biblioteke
    startGlewLibrary();

    // ++++++++++++++++++++++++++++++++++++++++++++++++++++++ RENDER LOOP - PETLJA ZA CRTANJE +++++++++++++++++++++++++++++++++++++++++++++++++

    createBackground();

    const double targetFrameTime = 1.0 / 60.0; // 60 FPS (16.67 ms per frame)
    double previousTime = glfwGetTime();
    double currentTime;
    double deltaTime;

    unsigned int unifiedShader = createShader("basic.vert", "basic.frag");

    float pianoWidth = 2.0;
    float startXPiano = -1.0;


    float keyWidthWhite = 0.13f;
    float keyHeight = 1.0f;
    float startXWhite = -0.975f;

    float startXBlack[] = { -0.955f, -0.825f, -0.565f, -0.435,  -0.305 ,  -0.045f, 0.085f,   0.345f, 0.475, 0.605 };





    float keyWidthBlack = 0.075f;

    float startXSheet = -0.31;
    float sheetWidth = 0.6;

    const int numWhiteKeys = 15;
    const int numBlackKeys = 10; // half of black keys, total number is 10

    vector<float> vertices;

    addPianoFrame(&vertices, startXPiano, pianoWidth);

    addWhiteKeys(&vertices, numWhiteKeys, startXWhite, keyWidthWhite);

     for (int i = 0; i < 10; i++)
         addBlackKey(&vertices, startXBlack[i], keyWidthBlack);


     addPianoSheet(&vertices, startXSheet, sheetWidth);
     addBackground(&vertices);
     addVolume(&vertices);

     addButton(&vertices, -0.955);
     addButton(&vertices, -0.855);
     addButton(&vertices, -0.755);
     addButton(&vertices, -0.655);
     addButton(&vertices, -0.555);
     addButton(&vertices, -0.455);

    const int size = numWhiteKeys * 6 * 4 + numBlackKeys * 6 * 4 + 240;
    float staticVertices[size];

    copy(vertices.begin(), vertices.end(), staticVertices);



    unsigned int stride = (2 + 2) * sizeof(float);

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(staticVertices), staticVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, stride, (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, stride, (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    unsigned whiteKeyTexture = loadImageToTexture("res/whiteKey.png");
    unsigned blackKeyTexture = loadImageToTexture("res/blackKey.png");
    unsigned pianoFrameTexture = loadImageToTexture("res/pianoFrame.png");
    unsigned sheetTexture = loadImageToTexture("res/emptySheet.png");
    unsigned volumeTexture = loadImageToTexture("res/100.png");
   

    unsigned pressedWhiteKeyTexture = loadImageToTexture("res/pressedWhiteKey.png");
    unsigned pressedBlackKeyTexture = loadImageToTexture("res/pressedBlackKey.png");

    unsigned backgroundTexture = loadImageToTexture("res/orchestraBackground.png");
    //unsigned textures[101] = { whiteKeyTexture, blackKeyTexture, pianoFrameTexture, sheetTexture, pressedCTexture, pressedDTexture, pressedETexture, pressedFTexture, pressedGTexture, pressedATexture, pressedHTexture, pressedWhiteKeyTexture };
    
    unsigned piano1Texture = loadImageToTexture("res/piano1.png");
    unsigned pressedPiano1Texture = loadImageToTexture("res/piano1Pressed.png");
    unsigned piano2Texture = loadImageToTexture("res/piano2.png");
    unsigned pressedPiano2Texture = loadImageToTexture("res/piano2Pressed.png");
    unsigned violinTexture = loadImageToTexture("res/violin.png");
    unsigned pressedViolinTexture = loadImageToTexture("res/violinPressed.png");

    unsigned recordTexture = loadImageToTexture("res/record.png");
    unsigned pressedRecordTexture = loadImageToTexture("res/recordPressed.png");
    unsigned stopTexture = loadImageToTexture("res/stop.png");
    unsigned pressedStopTexture = loadImageToTexture("res/stopPressed.png");
    unsigned playTexture = loadImageToTexture("res/play.png");
    unsigned pressedPlayTexture = loadImageToTexture("res/playPressed.png");


    glfwSetScrollCallback(window, scroll_callback);
 
  //  glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_TRUE);

    createCustomCursor(window);
    bool isRecording = false;
    bool isPressed = false;

    char firstNoteSet[26][15] = { "res/C3.mp3", "res/C4.mp3", "res/C5.mp3", "res/D3.mp3", "res/D4.mp3", "res/E3.mp3", "res/E4.mp3", "res/F3.mp3", "res/F4.mp3", 
    "res/G3.mp3", "res/G4.mp3", "res/A3.mp3", "res/A4.mp3", "res/B3.mp3", "res/B4.mp3", "res/Db3.mp3", "res/Db4.mp3", "res/Eb3.mp3", "res/Eb4.mp3", 
    "res/Gb3.mp3", "res/Gb4.mp3", "res/Ab3.mp3", "res/Ab4.mp3", "res/Bb3.mp3", "res/Bb4.mp3"};

    char violinNoteSet[26][15] = { "res/VC4.mp3", "res/VC5.mp3", "res/VC6.mp3", "res/VD4.mp3", "res/VD5.mp3", "res/VE4.mp3", "res/VE5.mp3", "res/VF4.mp3", "res/VF5.mp3",
   "res/VG4.mp3", "res/VG5.mp3", "res/VA4.mp3", "res/VA5.mp3", "res/VB4.mp3", "res/VB5.mp3", "res/VDb4.mp3", "res/VDb5.mp3", "res/VEb4.mp3", "res/VEb5.mp3",
   "res/VGb4.mp3", "res/VGb5.mp3", "res/VAb4.mp3", "res/VAb5.mp3", "res/VBb4.mp3", "res/VBb5.mp3" };

    char secondNoteSet[26][15] = { "res/C5.mp3", "res/C6.mp3", "res/C7.mp3", "res/D5.mp3", "res/D6.mp3", "res/E5.mp3", "res/E6.mp3", "res/F5.mp3", "res/F6.mp3",
 "res/G5.mp3", "res/G6.mp3", "res/A5.mp3", "res/A6.mp3", "res/B5.mp3", "res/B6.mp3", "res/Db5.mp3", "res/Db6.mp3", "res/Eb5.mp3", "res/Eb6.mp3",
 "res/Gb5.mp3", "res/Gb6.mp3", "res/Ab5.mp3", "res/Ab6.mp3", "res/Bb5.mp3", "res/Bb6.mp3" };

    char chosenNoteSet[26][15];
    memcpy(chosenNoteSet, firstNoteSet, sizeof(firstNoteSet));
   
    while (!shouldClose(window)) //Beskonacna petlja iz koje izlazimo tek kada prozor treba da se zatvori
    {

        currentTime = glfwGetTime();
        deltaTime = currentTime - previousTime;

        //Unos od korisnika bez callback funckcije. GLFW_PRESS = Dugme je trenutno pritisnuto. GLFW_RELEASE = Dugme trenutno nije pritisnuto
        if (escapePressed(window))
        {
            closeWindow(window);
        }

        //Brisanje ekrana
        glClear(GL_COLOR_BUFFER_BIT);



        glBindVertexArray(VAO);

        //   activateTextures(textures);


        int triangleNum = numWhiteKeys * 6 + numBlackKeys * 6 + 6 + 6;


        

        glfwSetCursorPosCallback(window, cursor_position_callback);
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);


        setUpTexture(backgroundTexture, unifiedShader);
        glActiveTexture(GL_TEXTURE0);
        glUseProgram(unifiedShader);
        glBindTexture(GL_TEXTURE_2D, backgroundTexture);
        glDrawArrays(GL_TRIANGLES, 12 + numWhiteKeys * 6 + 6 * numBlackKeys, 6);

        drawBackground(numWhiteKeys, numBlackKeys, unifiedShader, backgroundTexture);
        drawPianoFrame(unifiedShader, pianoFrameTexture);
        drawWhiteKeys(numWhiteKeys, unifiedShader, whiteKeyTexture);
        drawBlackKeys(numWhiteKeys, numBlackKeys, unifiedShader, blackKeyTexture);
        showEmptySheet(numWhiteKeys, numBlackKeys, unifiedShader, sheetTexture);
        drawVolume(numWhiteKeys, numBlackKeys, unifiedShader, volumeTexture);

        drawButton(24, numWhiteKeys, numBlackKeys, unifiedShader, recordTexture);
        drawButton(30, numWhiteKeys, numBlackKeys, unifiedShader, stopTexture);
        drawButton(36, numWhiteKeys, numBlackKeys, unifiedShader, playTexture);

        drawButton(42, numWhiteKeys, numBlackKeys, unifiedShader, piano1Texture);
        drawButton(48, numWhiteKeys, numBlackKeys, unifiedShader, piano2Texture);
        drawButton(54, numWhiteKeys, numBlackKeys, unifiedShader, violinTexture);

        if (firstSetPressed(window, xpos, ypos))
        {
            memcpy(chosenNoteSet, firstNoteSet, sizeof(firstNoteSet));
            drawButton(42, numWhiteKeys, numBlackKeys, unifiedShader, pressedPiano1Texture);
        }


        if (violinPressed(window, xpos, ypos))
        {
            memcpy(chosenNoteSet, violinNoteSet, sizeof(violinNoteSet));
            drawButton(54, numWhiteKeys, numBlackKeys, unifiedShader, pressedViolinTexture);
        }
        if (secondSetPressed(window, xpos, ypos))
        {
            
            memcpy(chosenNoteSet, secondNoteSet, sizeof(secondNoteSet));
            drawButton(48, numWhiteKeys, numBlackKeys, unifiedShader, pressedPiano2Texture);
        }

        if (recordPressedMain(window, xpos, ypos))
        {
            isRecording = true;
            drawButton(24, numWhiteKeys, numBlackKeys, unifiedShader, pressedRecordTexture);
            
        }


        if(isEHandled)
            drawButton(30, numWhiteKeys, numBlackKeys, unifiedShader, pressedStopTexture);
      
         

        if (spacePressed(window, xpos, ypos))
        {
            drawButton(36, numWhiteKeys, numBlackKeys, unifiedShader, pressedPlayTexture);
            playSoundsFromFile("results/file_durations.txt");
           
        }
        if (CPressed(window, xpos, ypos))
        {
            // playC3();
            unsigned pressedCTexture = loadImageToTexture("res/c.png");
            xpos = convertX(window, xpos);
            
            writeOnSheet(numWhiteKeys, numBlackKeys, unifiedShader, pressedCTexture);
            pressC(numWhiteKeys, unifiedShader, xpos, window, pressedWhiteKeyTexture, isRecording, isPressed, chosenNoteSet[0], chosenNoteSet[1], chosenNoteSet[2]);
            drawBlackKeys(numWhiteKeys, numBlackKeys, unifiedShader, blackKeyTexture);


        }
      
            
        if (CisPressed(window, xpos, ypos))
        {
            unsigned pressedCisTexture = loadImageToTexture("res/c#.png");
            xpos = convertX(window, xpos);
            writeOnSheet(numWhiteKeys, numBlackKeys, unifiedShader, pressedCisTexture);
            pressBlackKey(numWhiteKeys, unifiedShader, xpos, window, 16, 21, chosenNoteSet[15], chosenNoteSet[16], GLFW_KEY_S, GLFW_KEY_5, pressedBlackKeyTexture, isRecording, isPressed);
           
        }


        if (DPressed(window, xpos, ypos))
        {
            xpos = convertX(window, xpos);
            unsigned pressedDTexture = loadImageToTexture("res/d.png");
            writeOnSheet(numWhiteKeys, numBlackKeys, unifiedShader, pressedDTexture);
            pressWhiteKey(numWhiteKeys, unifiedShader, xpos, window, 2, 9, chosenNoteSet[3], chosenNoteSet[4], GLFW_KEY_X, GLFW_KEY_T, pressedWhiteKeyTexture, isRecording, isPressed);
            drawBlackKeys(numWhiteKeys, numBlackKeys, unifiedShader, blackKeyTexture);
         
        }


        if (DisPressed(window, xpos, ypos))
        {
            // playC3();
            xpos = convertX(window, xpos);
            unsigned pressedDisTexture = loadImageToTexture("res/d#.png");
            writeOnSheet(numWhiteKeys, numBlackKeys, unifiedShader, pressedDisTexture);
            pressBlackKey(numWhiteKeys, unifiedShader, xpos, window, 17, 22, chosenNoteSet[17], chosenNoteSet[18], GLFW_KEY_D, GLFW_KEY_6, pressedBlackKeyTexture, isRecording, isPressed);

        }

        if (EPressed(window, xpos, ypos))
        {
            xpos = convertX(window, xpos);
            unsigned pressedETexture = loadImageToTexture("res/e.png");
            writeOnSheet(numWhiteKeys, numBlackKeys, unifiedShader, pressedETexture);
            pressWhiteKey(numWhiteKeys, unifiedShader, xpos, window, 3, 10, chosenNoteSet[5], chosenNoteSet[6], GLFW_KEY_C, GLFW_KEY_Y, pressedWhiteKeyTexture, isRecording, isPressed);
            drawBlackKeys(numWhiteKeys, numBlackKeys, unifiedShader, blackKeyTexture);

        }

        if (FPressed(window, xpos, ypos))
        {
            xpos = convertX(window, xpos);
            unsigned pressedFTexture = loadImageToTexture("res/f.png");
            writeOnSheet(numWhiteKeys, numBlackKeys, unifiedShader, pressedFTexture);
            pressWhiteKey(numWhiteKeys, unifiedShader, xpos, window, 4, 11, chosenNoteSet[7], chosenNoteSet[8], GLFW_KEY_V, GLFW_KEY_U, pressedWhiteKeyTexture, isRecording, isPressed);
            drawBlackKeys(numWhiteKeys, numBlackKeys, unifiedShader, blackKeyTexture);

        }

        if (FisPressed(window, xpos, ypos))
        {
            // playC3();
            xpos = convertX(window, xpos);
            unsigned pressedFisTexture = loadImageToTexture("res/f#.png");
            writeOnSheet(numWhiteKeys, numBlackKeys, unifiedShader, pressedFisTexture);
            pressBlackKey(numWhiteKeys, unifiedShader, xpos, window, 18, 23, chosenNoteSet[19], chosenNoteSet[20], GLFW_KEY_G, GLFW_KEY_8, pressedBlackKeyTexture, isRecording, isPressed);

        }

        if (GPressed(window, xpos, ypos))
        {
            xpos = convertX(window, xpos);
            unsigned pressedGTexture = loadImageToTexture("res/g.png");
            writeOnSheet(numWhiteKeys, numBlackKeys, unifiedShader, pressedGTexture);
            pressWhiteKey(numWhiteKeys, unifiedShader, xpos, window, 5, 12, chosenNoteSet[9], chosenNoteSet[10], GLFW_KEY_B, GLFW_KEY_I, pressedWhiteKeyTexture, isRecording, isPressed);
            drawBlackKeys(numWhiteKeys, numBlackKeys, unifiedShader, blackKeyTexture);

        }

        if (GisPressed(window, xpos, ypos))
        {
            // playC3();
            xpos = convertX(window, xpos);
            unsigned pressedGisTexture = loadImageToTexture("res/g#.png");
            writeOnSheet(numWhiteKeys, numBlackKeys, unifiedShader, pressedGisTexture);
            pressBlackKey(numWhiteKeys, unifiedShader, xpos, window, 19, 24, chosenNoteSet[21], chosenNoteSet[22], GLFW_KEY_H, GLFW_KEY_9, pressedBlackKeyTexture, isRecording, isPressed);

        }

        if (APressed(window, xpos, ypos))
        {
            xpos = convertX(window, xpos);
            unsigned pressedATexture = loadImageToTexture("res/a.png");
            writeOnSheet(numWhiteKeys, numBlackKeys, unifiedShader, pressedATexture);
            pressWhiteKey(numWhiteKeys, unifiedShader, xpos, window, 6, 13, chosenNoteSet[11], chosenNoteSet[12], GLFW_KEY_N, GLFW_KEY_O, pressedWhiteKeyTexture, isRecording, isPressed);
            drawBlackKeys(numWhiteKeys, numBlackKeys, unifiedShader, blackKeyTexture);

        }

        if (AisPressed(window, xpos, ypos))
        {
            // playC3();
            xpos = convertX(window, xpos);
            unsigned pressedAisTexture = loadImageToTexture("res/a#.png");
            writeOnSheet(numWhiteKeys, numBlackKeys, unifiedShader, pressedAisTexture);
            pressBlackKey(numWhiteKeys, unifiedShader, xpos, window, 20, 25, chosenNoteSet[23], chosenNoteSet[24], GLFW_KEY_J, GLFW_KEY_0, pressedBlackKeyTexture, isRecording, isPressed);

        }

        if (HPressed(window, xpos, ypos))
        {
            xpos = convertX(window, xpos);
            unsigned pressedHTexture = loadImageToTexture("res/h.png");
            writeOnSheet(numWhiteKeys, numBlackKeys, unifiedShader, pressedHTexture);
            pressWhiteKey(numWhiteKeys, unifiedShader, xpos, window, 7, 14, chosenNoteSet[13], chosenNoteSet[14], GLFW_KEY_M, GLFW_KEY_P, pressedWhiteKeyTexture, isRecording, isPressed);
            drawBlackKeys(numWhiteKeys, numBlackKeys, unifiedShader, blackKeyTexture);

        }

        if (leftArrow(window))
        {
         //   std::cout << "uslo";
            VolumeDown();
            int volume = getVolumePercentage();
            string volumeTex = "res/" + to_string(volume) + ".png";
            volumeTexture = loadImageToTexture(volumeTex.c_str());
        }

        if (rightArrow(window))
        {
            //   std::cout << "uslo";
            VolumeUp();
            int volume = getVolumePercentage();
            string volumeTex = "res/" + to_string(volume) + ".png";
            volumeTexture = loadImageToTexture(volumeTex.c_str());
            drawVolume(numWhiteKeys, numBlackKeys, unifiedShader, volumeTexture);
        }

        if (isScroll)
        {
            int volume = getVolumePercentage();
            string volumeTex = "res/" + to_string(volume) + ".png";
            volumeTexture = loadImageToTexture(volumeTex.c_str());
            drawVolume(numWhiteKeys, numBlackKeys, unifiedShader, volumeTexture);
        }

        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS)
        {
            xpos = convertX(window, xpos);
            ypos = convertY(window, ypos);
          //  cout << "X " << xpos << endl;
          
            if (ypos <= 0.87 && ypos >= 0.73)
            {
                if (xpos <= 0.86 && xpos >= 0.848)
                {
                    int volume = 100;
                    string volumeTex = "res/" + to_string(volume) + ".png";
                    volumeTexture = loadImageToTexture(volumeTex.c_str());
                    drawVolume(numWhiteKeys, numBlackKeys, unifiedShader, volumeTexture);
                }

                if (xpos <= 0.85 && xpos >= 0.82)
                {
                    int volume = 90;
                    string volumeTex = "res/" + to_string(volume) + ".png";
                    volumeTexture = loadImageToTexture(volumeTex.c_str());
                    drawVolume(numWhiteKeys, numBlackKeys, unifiedShader, volumeTexture);
                }

                if (xpos < 0.82 && xpos >= 0.78)
                {
                    int volume = 80;
                    string volumeTex = "res/" + to_string(volume) + ".png";
                    volumeTexture = loadImageToTexture(volumeTex.c_str());
                    drawVolume(numWhiteKeys, numBlackKeys, unifiedShader, volumeTexture);
                }

                if (xpos < 0.78 && xpos >= 0.74)
                {
                    int volume = 70;
                    string volumeTex = "res/" + to_string(volume) + ".png";
                    volumeTexture = loadImageToTexture(volumeTex.c_str());
                    drawVolume(numWhiteKeys, numBlackKeys, unifiedShader, volumeTexture);
                }

                if (xpos < 0.74 && xpos >= 0.7)
                {
                    int volume = 60;
                    string volumeTex = "res/" + to_string(volume) + ".png";
                    volumeTexture = loadImageToTexture(volumeTex.c_str());
                    drawVolume(numWhiteKeys, numBlackKeys, unifiedShader, volumeTexture);
                }

                if (xpos < 0.7 && xpos >= 0.66)
                {
                    int volume = 60;
                    string volumeTex = "res/" + to_string(volume) + ".png";
                    volumeTexture = loadImageToTexture(volumeTex.c_str());
                    drawVolume(numWhiteKeys, numBlackKeys, unifiedShader, volumeTexture);
                }

                if (xpos < 0.66 && xpos >= 0.62)
                {
                    int volume = 50;
                    string volumeTex = "res/" + to_string(volume) + ".png";
                    volumeTexture = loadImageToTexture(volumeTex.c_str());
                    drawVolume(numWhiteKeys, numBlackKeys, unifiedShader, volumeTexture);
                }

                if (xpos < 0.62 && xpos >= 0.58)
                {
                    int volume = 40;
                    string volumeTex = "res/" + to_string(volume) + ".png";
                    volumeTexture = loadImageToTexture(volumeTex.c_str());
                    drawVolume(numWhiteKeys, numBlackKeys, unifiedShader, volumeTexture);
                }

                if (xpos < 0.58 && xpos >= 0.54)
                {
                    int volume = 30;
                    string volumeTex = "res/" + to_string(volume) + ".png";
                    volumeTexture = loadImageToTexture(volumeTex.c_str());
                    drawVolume(numWhiteKeys, numBlackKeys, unifiedShader, volumeTexture);
                }

                if (xpos < 0.54 && xpos >= 0.5)
                {
                    int volume = 20;
                    string volumeTex = "res/" + to_string(volume) + ".png";
                    volumeTexture = loadImageToTexture(volumeTex.c_str());
                    drawVolume(numWhiteKeys, numBlackKeys, unifiedShader, volumeTexture);
                }
                if (xpos < 0.5 && xpos >= 0.46)
                {
                    int volume = 10;
                    string volumeTex = "res/" + to_string(volume) + ".png";
                    volumeTexture = loadImageToTexture(volumeTex.c_str());
                    drawVolume(numWhiteKeys, numBlackKeys, unifiedShader, volumeTexture);
                }

                if (xpos < 0.46 && xpos >= 0.37)
                {
                    int volume = 0;
                    string volumeTex = "res/" + to_string(volume) + ".png";
                    volumeTexture = loadImageToTexture(volumeTex.c_str());
                    drawVolume(numWhiteKeys, numBlackKeys, unifiedShader, volumeTexture);
                }

            }

        }


     
        if (stopPressedMain(window, xpos, ypos))
        {
            writeToFile();
        }
        glBindTexture(GL_TEXTURE_2D, 0);
        glBindVertexArray(0);
        glUseProgram(0);
    //    stop(engine);

        setUpScreen(window);

        if (deltaTime < targetFrameTime) {
            std::this_thread::sleep_for(std::chrono::duration<double>(targetFrameTime - deltaTime));
        }

        // Update previous time for the next frame
        previousTime = glfwGetTime();



    }

    // ++++++++++++++++++++++++++++++++++++++++++++++++++++++ POSPREMANJE +++++++++++++++++++++++++++++++++++++++++++++++++

    //Sve OK - batali program
    glfwTerminate();
    return 0;
}


