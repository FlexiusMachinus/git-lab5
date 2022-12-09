#pragma once

#include <stdexcept>
#include "shapes_stack.h"

namespace shapes
{
	ShapesStack::ShapesStack(size_t capacity)
	{
		mCapacity = capacity;
		mElems = new shapes::Shape*[capacity];
		mTop = 0;
	}

	ShapesStack::~ShapesStack()
	{
		delete[] mElems;
	}

	bool ShapesStack::isEmpty() const
	{
		return (mTop == mCapacity);
	}
	
	bool ShapesStack::isFull() const
	{
		return (mTop == mCapacity);
	}

	Shape* ShapesStack::pop()
	{
		if (isEmpty())
			throw std::exception("Стек пуст");
		return mElems[--mTop];
	}
	
	void ShapesStack::push(Shape* value)
	{
		if (isFull())
			throw std::exception("Стек переполнен");
		mElems[mTop++] = value;
	}
};