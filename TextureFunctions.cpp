#include "TextureFunctions.h"
#include <vector>
namespace TextureFunctions {



    void setUpTexture(unsigned texture, unsigned int shader)
    {
        
        glBindTexture(GL_TEXTURE_2D, texture); //Podesavamo teksturu
        glGenerateMipmap(GL_TEXTURE_2D); //Generisemo mipmape 
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);//S = U = X    GL_REPEAT, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_BORDER
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);// T = V = Y
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);   //GL_NEAREST, GL_LINEAR
        glBindTexture(GL_TEXTURE_2D, 0);
        glUseProgram(shader);
        unsigned uTexLoc = glGetUniformLocation(shader, "uTex");
        glUniform1i(uTexLoc, 0); // Indeks teksturne jedinice (sa koje teksture ce se citati boje)
        glUseProgram(0);
     }
   

    

}
