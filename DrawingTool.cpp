#include "DrawingTool.h"

#include "TextureFunctions.h"

using namespace TextureFunctions;

namespace DrawingTool {

	void drawPianoFrame(unsigned int unifiedShader, unsigned texture)
	{
		setUpTexture(texture, unifiedShader);
		glActiveTexture(GL_TEXTURE0);
		glUseProgram(unifiedShader);
		glBindTexture(GL_TEXTURE_2D, texture);
		glDrawArrays(GL_TRIANGLES, 0, 6);

		
	}
	void drawWhiteKeys(int numWhiteKeys, unsigned int unifiedShader, unsigned texture)
	{
		setUpTexture(texture, unifiedShader);
		glActiveTexture(GL_TEXTURE0);
		glUseProgram(unifiedShader);
		glBindTexture(GL_TEXTURE_2D, texture);
		glDrawArrays(GL_TRIANGLES, 6, numWhiteKeys * 6);
		
	}
	void drawBlackKeys(int numWhiteKeys, int numBlackKeys, unsigned int unifiedShader, unsigned texture) {

		setUpTexture(texture, unifiedShader);
		glActiveTexture(GL_TEXTURE0);
		glUseProgram(unifiedShader);
		glBindTexture(GL_TEXTURE_2D, texture);
		glDrawArrays(GL_TRIANGLES, 6 + numWhiteKeys * 6, numBlackKeys * 6);
		
	}
	void showEmptySheet(int numWhiteKeys, int numBlackKeys, unsigned int unifiedShader, unsigned texture) {
		setUpTexture(texture, unifiedShader);
		glActiveTexture(GL_TEXTURE0);
		glUseProgram(unifiedShader);
		glBindTexture(GL_TEXTURE_2D, texture);
		glDrawArrays(GL_TRIANGLES, 6 + numWhiteKeys * 6 + 6 * numBlackKeys, 6);
		

	}
	void writeOnSheet(int numWhiteKeys, int numBlackKeys, unsigned int unifiedShader, unsigned texture)
	{
		setUpTexture(texture, unifiedShader);
		glActiveTexture(GL_TEXTURE0);
		glUseProgram(unifiedShader);
		glBindTexture(GL_TEXTURE_2D, texture);
		glDrawArrays(GL_TRIANGLES, 6 + numWhiteKeys * 6 + 6 * numBlackKeys, 6);
		
	}

	void drawBackground(int numWhiteKeys, int numBlackKeys, unsigned int unifiedShader, unsigned texture)
	{
		
		
		setUpTexture(texture, unifiedShader);
		glActiveTexture(GL_TEXTURE0);
		glUseProgram(unifiedShader);
		glBindTexture(GL_TEXTURE_2D, texture);
		glDrawArrays(GL_TRIANGLES, 12 + numWhiteKeys * 6 + 6 * numBlackKeys, 6);

	}

	void drawVolume(int numWhiteKeys, int numBlackKeys, unsigned int unifiedShader, unsigned texture)
	{
		setUpTexture(texture, unifiedShader);
		glActiveTexture(GL_TEXTURE0);
		glUseProgram(unifiedShader);
		glBindTexture(GL_TEXTURE_2D, texture);
		glDrawArrays(GL_TRIANGLES, 18 + numWhiteKeys * 6 + 6 * numBlackKeys, 6);

	}

	void drawButton(int firstNum, int numWhiteKeys, int numBlackKeys, unsigned int unifiedShader, unsigned texture)
	{
		setUpTexture(texture, unifiedShader);
		glActiveTexture(GL_TEXTURE0);
		glUseProgram(unifiedShader);
		glBindTexture(GL_TEXTURE_2D, texture);
		glDrawArrays(GL_TRIANGLES, firstNum + numWhiteKeys * 6 + 6 * numBlackKeys, 6);
	}

	




	void pressC(int numWhiteKeys, unsigned int unifiedShader, double xpos, GLFWwindow* window, unsigned texture, bool keyHandle, bool isPressed, char file1[], char file2[], char file3[])
	{
		setUpTexture(texture, unifiedShader);
		glActiveTexture(GL_TEXTURE0);
		glUseProgram(unifiedShader);
		glBindTexture(GL_TEXTURE_2D, texture);

		if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS)
		{
			if (xpos < -0.975 + 7 * 0.13)
			{
			   glDrawArrays(GL_TRIANGLES, 6, 6);
			   playSound(file1, window, keyHandle, isPressed, GLFW_MOUSE_BUTTON_1);
			  
			  
			}
			else if (xpos >= -0.975 + 7 * 0.13 && xpos < -0.975f + 14 * 0.13)
			{
				glDrawArrays(GL_TRIANGLES, 8 * 6, 6);
				playSound(file2, window, keyHandle, isPressed, GLFW_MOUSE_BUTTON_1);
				
			}
			else if ((xpos >= -0.975f + 14 * 0.13 && xpos <= -0.845f + 14 * 0.13))
			{
				glDrawArrays(GL_TRIANGLES, 15 * 6, 6);
				playSound(file3, window, keyHandle, isPressed, GLFW_MOUSE_BUTTON_1);
			

			}
		}
		else
		{
			if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
			{

				glDrawArrays(GL_TRIANGLES, 6, 6);
				playSound(file1, window, keyHandle, isPressed, GLFW_KEY_Z);
			 
			}
			if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
			{
				glDrawArrays(GL_TRIANGLES, 8 * 6, 6);
				playSound(file2, window, keyHandle, isPressed, GLFW_KEY_R);
			   
			}
			if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
			{
				glDrawArrays(GL_TRIANGLES, 15 * 6, 6);
				playSound(file3, window, keyHandle, isPressed, GLFW_KEY_Q);
				

			}
		}
	
	
	
	}

	void pressWhiteKey(int numWhiteKeys, unsigned int unifiedShader, double xpos, GLFWwindow* window, int num1, int num2, std::string filePath1, std::string filePath2, int key1, int key2, unsigned texture, bool keyHandle, bool isPressed)
	{
		setUpTexture(texture, unifiedShader);
		glActiveTexture(GL_TEXTURE0);
		glUseProgram(unifiedShader);
		glBindTexture(GL_TEXTURE_2D, texture);
		if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS)
		{
			if (xpos < -0.975 + 7 * 0.13)
			{	glDrawArrays(GL_TRIANGLES, num1 * 6, 6);
				playSound(filePath1, window, keyHandle, isPressed, GLFW_MOUSE_BUTTON_1);
			}
			else
			{ 
				
				glDrawArrays(GL_TRIANGLES, num2 * 6, 6);
				playSound(filePath2, window, keyHandle, isPressed, GLFW_MOUSE_BUTTON_1);
				
			}
		}
		else
		{
			if (glfwGetKey(window, key1) == GLFW_PRESS)
			{
				glDrawArrays(GL_TRIANGLES, num1 * 6, 6);
				playSound(filePath1, window, keyHandle, isPressed, key1);
			}
			if (glfwGetKey(window, key2) == GLFW_PRESS)
			{

				glDrawArrays(GL_TRIANGLES, num2 * 6, 6);
				playSound(filePath2, window, keyHandle, isPressed, key2);
				//playSound(filePath2, window, keyHandle, isPressed, key);
				
			}
		}
		
	

		
	}


	void pressBlackKey(int numWhiteKeys, unsigned int unifiedShader, double xpos, GLFWwindow* window, int num1, int num2, std::string filePath1, std::string filePath2, int key1, int key2, unsigned texture, bool keyHandle, bool isPressed)
	{
		setUpTexture(texture, unifiedShader);
		glActiveTexture(GL_TEXTURE0);
		glUseProgram(unifiedShader);
		glBindTexture(GL_TEXTURE_2D, texture);
		if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS)
		{
			if (xpos < -0.955 + 0.075 + 7 * 0.13)
			{
				glDrawArrays(GL_TRIANGLES, num1 * 6, 6);
				playSound(filePath1, window, keyHandle, isPressed, GLFW_MOUSE_BUTTON_1);
			}
			else
			{

				glDrawArrays(GL_TRIANGLES, num2 * 6, 6);
				playSound(filePath2, window, keyHandle, isPressed, GLFW_MOUSE_BUTTON_1);

			}
		}
		else
		{
			if (glfwGetKey(window, key1) == GLFW_PRESS)
			{
				glDrawArrays(GL_TRIANGLES, num1 * 6, 6);
				playSound(filePath1, window, keyHandle, isPressed, key1);

			}
			if (glfwGetKey(window, key2) == GLFW_PRESS)
			{

				glDrawArrays(GL_TRIANGLES, num2 * 6, 6);
				playSound(filePath2, window, keyHandle, isPressed, key2);

			}
		}




	}


	

	
}