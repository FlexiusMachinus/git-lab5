#include <iostream>
#include <windows.h>
#include <windowsx.h>

#include "composite_shape.h"
#include "shapes_stack.h"

using namespace shapes;

// Параметры фигур
const int SHAPES_WIDTH = 400;
const int SHAPES_HEIGHT = 200;
const COLORREF R_COLOR = RGB(3, 252, 165);
const COLORREF E_COLOR = RGB(3, 186, 252);
const COLORREF S_COLOR = RGB(0, 78, 122);

int main()
{
	// Язык и заголовок консоли
	setlocale(LC_ALL, "");
	SetConsoleTitle("19VP2_7_Figures");

	// Дескриптор окна консоли
	HWND hwnd = GetConsoleWindow();
	if (hwnd == NULL)
	{
		std::cerr << "Не удалось получить дескриптор окна\n";
		return -1;
	}

	// Контекст окна
	Window* context = new Window(hwnd, GetDC(hwnd));

	// Стек фигур
	auto shapes = new ShapesStack(3);

	// Начальное положение фигур
	const int x = context->getClientRectangle().right / 2;
	const int y = context->getClientRectangle().bottom / 2;

	auto shape = shapes::CompositeShape(context, x, y, SHAPES_WIDTH, SHAPES_HEIGHT, R_COLOR, E_COLOR, S_COLOR);
	shapes->push(&shape);

	// Отрисовка фигур
	shape.draw();
	system("pause");

	// Перемещение фигур
	shapes->pop()->moveTo(x + 150, y - 500);
	system("pause > nul");

	delete shapes;
	delete context;
	
	return 0;
}
