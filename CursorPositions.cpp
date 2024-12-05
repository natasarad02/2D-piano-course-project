#include "CursorPositions.h"
using namespace std;
namespace CursorPositions {

	bool cursorOnC(double xpos, double ypos)
	{
		//return xpos >= -0.975f && xpos <= -0.845f;
		
		if (ypos >= -0.1 && ypos <= 0.5)
		{
			if ((xpos >= -0.975f + 14 * 0.13 && xpos <= -0.845f + 14 * 0.13))
				return true;

			if ((xpos >= -0.975f && xpos <= -0.955f + 0.075f) || (xpos >= -0.975f + 7 * 0.13 && xpos <= -0.955f + 7 * 0.13 + 0.075f))
			{

				return true;
			}
			else
				return false;
		}
		else if (ypos >= -0.5 && ypos <= -0.1)
		{
			if ((xpos >= -0.975f + 14 * 0.13 && xpos <= -0.845f + 14 * 0.13))
				return true;

			if ((xpos >= -0.975f && xpos <= -0.845f) || (xpos >= -0.975f + 7 * 0.13 && xpos <= -0.845f + 7 * 0.13))
				return true;

			else
				return false;
		}
		else
			return false;

		return false;
	}


	bool cursorOnWhiteKey(double xpos, double ypos, int widthParam, int offset1, int offset2)
	{

		if (ypos >= -0.1 && ypos <= 0.5)
		{

			if ((xpos >= -0.975f + widthParam * 0.13 + offset1 * 0.075 / 2 && xpos <= -0.955f + widthParam * 0.13 + offset2 * 0.075f) || (xpos >= -0.975f + (7 + widthParam) * 0.13 + offset1 *  0.075 / 2 && xpos <= -0.955f + (7 + widthParam) * 0.13 + offset2 * 0.075f))
			{

				return true;
			}
			else
				return false;
		}
		else if (ypos >= -0.5 && ypos <= -0.1)
		{

			if ((xpos >= -0.975f + widthParam * 0.13 && xpos <= -0.845f + widthParam * 0.13) || (xpos >= -0.975f + (7 + widthParam) * 0.13 && xpos <= -0.845f + (7 + widthParam) * 0.13))
				return true;

			else
				return false;
		}
		else
			return false;

		return false;
	}


	bool cursorOnBlackKey(double xpos, double ypos, int widthParam)
	{

		if (ypos <= 0.5 && ypos >= -0.1)
		{
			if ((xpos >= -0.955f + 0.075 + widthParam * 0.13 && xpos <= -0.955f + 0.075 + widthParam * 0.13 + 0.075f) || (xpos >= -0.955f + 0.075 + (7 + widthParam) * 0.13 && xpos <= -0.955f + 0.075 + (7 + widthParam) * 0.13 + 0.075f))
			{

				return true;
			}
			else
				return false;

		}
		else
			return false;

		
	
	}

	

}
