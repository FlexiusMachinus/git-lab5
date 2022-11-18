#pragma once

#include "window.h"
#include <exception>

namespace shapes
{
	class Shape
	{
	public:
		Shape(Window* window, int x, int y, COLORREF color, COLORREF strokeColor);
		virtual ~Shape();
		
		virtual void draw();
		virtual void hide();
		virtual void moveTo(int x, int y) = 0;
		
		class OutOfBounds : std::exception{};

	protected:
		Window* mWindow;
		HBRUSH mBrush;
		HPEN mPen;
		
		int mX;
		int mY;

		bool mHidden;
	};
}
