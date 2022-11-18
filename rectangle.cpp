#include "rectangle.h"
#include <windowsx.h>
#include <exception>

namespace shapes
{
	Rectangle::Rectangle(Window* window, int x, int y, int width, int height, COLORREF color, COLORREF strokeColor)
		: Shape(window, x, y, color, strokeColor)
	{
		if (width <= 0 || height <= 0)
			throw std::exception("Значения длины или высоты не могут быть отрицательными или равняться нулю");
		
		mLeft = x - width / 2;
		mTop = y - height / 2;
		mRight = x + width / 2;
		mBottom = y + height / 2;

		if (!mWindow->checkBounds(mLeft, mTop, mRight, mBottom))
			throw OutOfBounds();
	}

	void Rectangle::draw()
	{
		Shape::draw();
		HDC hdc = mWindow->getDeviceContext();
		SelectPen(hdc, mPen);
		SelectBrush(hdc, mBrush);
		::Rectangle(hdc, mLeft, mTop, mRight, mBottom);
	}

	void Rectangle::hide()
	{
		Shape::hide();
		mWindow->clearRectangle({ mLeft - 1, mTop - 1, mRight, mBottom });
	}

	void Rectangle::moveTo(int x, int y)
	{
		mX = x;
		mY = y;
		
		const bool isHidden = mHidden;
		if (!isHidden)
			hide();
		
		int width = mRight - mLeft;
		int height = mBottom - mTop;
		
		mLeft = x + width / 2;
		mTop = y + height / 2;
		mRight = x - width / 2;
		mBottom = y - height / 2;

		if (!mWindow->checkBounds(mLeft, mTop, mRight, mBottom))
			throw OutOfBounds();
		
		if (!isHidden)
			draw();
	}
}
