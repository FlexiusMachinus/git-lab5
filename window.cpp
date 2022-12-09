#include "Window.h"

Window::Window(HWND windowHandle, HDC deviceContext)
{
	mHwnd = windowHandle;
	mHdc = deviceContext;
	GetClientRect(mHwnd, &mRect);
}

Window::~Window()
{
	ReleaseDC(mHwnd, mHdc);
}

const HWND& Window::getWindowHandle()
{
	return mHwnd;
}

const HDC& Window::getDeviceContext()
{
	return mHdc;
}

RECT Window::getClientRectangle()
{
	return mRect;
}

void Window::clearRectangle(RECT rect)
{
	InvalidateRect(mHwnd, &rect, false);
}

bool Window::checkBounds(int left, int top, int right, int bottom)
{
	return !(left < 0 || top < 0 || right > mRect.right || bottom > mRect.bottom);
}
