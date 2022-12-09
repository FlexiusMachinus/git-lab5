#pragma once

#include "shape.h"

namespace shapes
{
	class ShapesStack
	{
	public:
		ShapesStack(size_t capacity);
		~ShapesStack();

		bool isEmpty() const;
		bool isFull() const;

		Shape* pop();
		void push(Shape* value);

	private:
		size_t mCapacity;
		size_t mTop;
		Shape** mElems;
	};
}