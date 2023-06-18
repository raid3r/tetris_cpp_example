#include "work_with_console.h"
#include <conio.h>

void SetColor(ConsoleColor text, ConsoleColor background)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (short)text | ((short)background << 4));
}
void SetColor(short text, short background)
{
	SetColor((ConsoleColor)text, (ConsoleColor)background);
}

void SetCursorPosition(const COORD& coord) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void SetCursorPosition(short x, short y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

int getKey() {
	if (_kbhit()) {
		return _getch();
	}
	return NO_KEY;
}