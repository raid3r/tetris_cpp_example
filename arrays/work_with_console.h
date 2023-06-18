#pragma once

#include <Windows.h>

enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	DarkYellow = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

enum Keys {
	BACKSPACE = 8,
	ESC = 27, ARROW_START = 224, ENTER = 13, SPACE = 32,
	F_KEY = 102,
	UP_ARROW = 72, DOWN_ARROW = 80, LEFT_ARROW = 75, RIGHT_ARROW = 77
};

void SetColor(ConsoleColor text, ConsoleColor background);
void SetColor(short text, short background);
void SetCursorPosition(const COORD& coord);
void SetCursorPosition(short x, short y);
void ShowConsoleCursor(bool showFlag);

const int NO_KEY = -1;

int getKey();
