#include "composite_shape.h"
#include <stdexcept>

namespace shapes
{
	CompositeShape::CompositeShape(Window* window, int x, int y, int width, int height, COLORREF rectColor, COLORREF ellipseColor, COLORREF strokeColor) : Shape(window, x, y, NULL, NULL),
		mRect(window, x, y, width, height, rectColor, strokeColor),
		mEllipse(window, x, y, width / 2, height / 2, ellipseColor, strokeColor)
	{
	}
	
	void CompositeShape::moveTo(int x, int y)
	{
		mX = x;
		mY = y;
		
		const bool isHidden = mHidden;
		if (!isHidden)
			this->hide();
		
		mRect.moveTo(x, y);
		mEllipse.moveTo(x, y);
		
		// Без задержки между инвалидацией и отрисовкой GDI некорректно выводит фигуры
		Sleep(1);
		if (!isHidden)
			this->draw();
	}

	void CompositeShape::draw()
	{
		Shape::draw();
		mRect.draw();
		mEllipse.draw();
	}

	void CompositeShape::hide()
	{
		Shape::hide();
		mRect.hide();
		mEllipse.hide();
	}
}
