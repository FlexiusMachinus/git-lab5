#pragma once

#include "rectangle.h"
#include "ellipse.h"

namespace shapes
{
	class CompositeShape : public Shape
	{
	public:
		CompositeShape(Window* window, int x, int y, int width, int height, COLORREF rectColor, COLORREF ellipseColor, COLORREF strokeColor = RGB(0, 0, 0));

		void draw() override;
		void hide() override;
		void moveTo(int x, int y) override;

	private:
		Rectangle mRect;
		Ellipse mEllipse;		
	};
}
