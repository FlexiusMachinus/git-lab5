#pragma once

#include "shape.h"

namespace shapes
{
	class Rectangle : public Shape
	{
	public:
		Rectangle(Window* window, int x, int y, int width, int height, COLORREF color, COLORREF strokeColor = RGB(0, 0, 0));

		void draw() override;
		void hide() override;
		void moveTo(int x, int y) override;

	protected:
		int mLeft;
		int mTop;
		int mRight;
		int mBottom;
	};
}
