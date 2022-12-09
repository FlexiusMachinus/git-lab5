#include "ellipse.h"
#include <windowsx.h>

namespace shapes
{
	Ellipse::Ellipse(Window* window, int x, int y, int majorAxisLength, int minorAxisLength, COLORREF color, COLORREF strokeColor)
		: Shape(window, x, y, color, strokeColor)
	{
		if (majorAxisLength <= 0 || minorAxisLength <= 0)
			throw std::exception("Значения длины или высоты не могут быть отрицательными или равняться нулю");
		
		mLeft = x + majorAxisLength;
		mTop = y + minorAxisLength;
		mRight = x - majorAxisLength;
		mBottom = y - minorAxisLength;

		if (!mWindow->checkBounds(mLeft, mTop, mRight, mBottom))
			throw OutOfBounds();
	}

	void Ellipse::draw()
	{
		Shape::draw();
		HDC hdc = mWindow->getDeviceContext();
		SelectPen(hdc, mPen);
		SelectBrush(hdc, mBrush);
		::Ellipse(hdc, mLeft, mTop, mRight, mBottom);
	}

	void Ellipse::hide()
	{
		Shape::hide();
		mWindow->clearRectangle({ mLeft - 1, mTop - 1, mRight, mBottom });
	}

	void Ellipse::moveTo(int x, int y)
	{
		mX = x;
		mY = y;

		int width = mRight - mLeft;
		int height = mBottom - mTop;
		
		const bool isHidden = mHidden;
		if (!isHidden)
			hide();
		
		mLeft = x + width / 2;
		mTop = y + height / 2;
		mRight = x - width / 2;
		mBottom = y - height / 2;

		if (!mWindow->checkBounds(mLeft, mTop, mRight, mBottom))
			throw OutOfBounds();

		if (!mHidden)
			draw();
	}
}
