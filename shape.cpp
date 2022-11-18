#include "shape.h"
#include <windowsx.h>

namespace shapes
{
	Shape::Shape(Window* window, int x, int y, COLORREF color, COLORREF strokeColor)
	{	
		mWindow = window;

		mX = x;
		mY = y;
		
		mBrush = CreateSolidBrush(color);
		mPen = CreatePen(PS_SOLID, 2, strokeColor);
	}

	Shape::~Shape()
	{
		DeleteBrush(mBrush);
		DeletePen(mPen);
	}

	void Shape::draw()
	{
		mHidden = false;
	}

	void Shape::hide()
	{
		mHidden = true;
	}

}
