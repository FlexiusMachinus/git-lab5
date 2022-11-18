#pragma once
#include <windows.h>

class Window
{
public:
	Window(HWND window, HDC deviceContext);
	~Window();
	
	const HWND& getWindowHandle();
	const HDC& getDeviceContext();
	RECT getClientRectangle();
	
	void clearRectangle(RECT rect);
	bool checkBounds(int left, int top, int right, int bottom);
	
private:
	HWND mHwnd;
	HDC mHdc;
	RECT mRect;
};
