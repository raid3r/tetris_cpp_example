#include "tetris_game.h"
#include <conio.h>

using namespace std;

void drawFrame(int posX, int posY, int width, int height, ConsoleColor color) {
	for (size_t x = posX; x < posX + width; x++)
	{

		for (size_t y = posY; y < posY + height; y++) {
			SetCursorPosition(x, y);
			if (x == posX || x == posX + width - 1 || y == posY || y == posY + height - 1) {
				SetColor(White, color);
				cout << " ";
			}
			else {
				SetColor(White, Black);
				cout << " ";
			}
		}
	}
	SetColor(White, Black);
}

void showMessage(string text, ConsoleColor textColor, ConsoleColor frameColor) {
	drawFrame(10, 10, 25, 5, frameColor);
	SetCursorPosition(12, 12);
	SetColor(textColor, Black);
	cout << text;
	SetColor(White, Black);
	_getch();
	drawFrame(10, 10, 25, 5, Black);
}

void game() {

	initFileld();
	drawFieldFrame();
	drawField();
	Figure temp;



	while (true)
	{
		Figure f = getRandomFigure();
		if (!canPlaceOnField(f)) {
			showMessage("GAME OVER", Red, Red);
			break;
		}

		int timerTime = 500;
		int timer = timerTime;
		int tick = 50;

		SetCursorPosition(25, 3);
		cout << "Points: " << points;

		printFigure(f);

		while (true)
		{
			if (points > 100) {
				showMessage("YOU WIN !", White, Green);
				break;
			}

			Sleep(tick);
			timer -= tick;
			if (timer < 0) {
				temp = cloneFigure(f);
				moveDown(temp);
				if (canPlaceOnField(temp)) {
					clearFigure(f);
					moveDown(f);
					printFigure(f);
					timer = timerTime;
				}
				else {
					putOnField(f);
					break;
				}
			}

			int key = getKey();
			bool newFigure = false;

			if (key != NO_KEY) {
				switch (key)
				{
				case ESC:
					showMessage("PAUSE", Green, Green);
					drawFieldFrame();
					drawField();
					printFigure(f);
					break;

				case DOWN_ARROW:
					temp = cloneFigure(f);
					moveDown(temp);
					if (canPlaceOnField(temp)) {
						clearFigure(f);
						moveDown(f);
						printFigure(f);
					}
					else {
						putOnField(f);
						newFigure = true;
						break;
					}
					break;
				case LEFT_ARROW:
					temp = cloneFigure(f);
					moveLeft(temp);
					if (canPlaceOnField(temp)) {
						clearFigure(f);
						moveLeft(f);
						printFigure(f);
					}
					break;
				case RIGHT_ARROW:
					temp = cloneFigure(f);
					moveRight(temp);
					if (canPlaceOnField(temp)) {
						clearFigure(f);
						moveRight(f);
						printFigure(f);
					}
					break;
				case UP_ARROW:
					temp = cloneFigure(f);
					rotate(temp);
					if (canPlaceOnField(temp)) {
						clearFigure(f);
						rotate(f);
						printFigure(f);
					}
					break;
				default:
					break;
				}

				if (newFigure) {
					break;
				}
			}
		}

	}
}

Figure cloneFigure(Figure f) {
	Figure clone;
	clone.color = f.color;
	clone.type = f.type;
	clone.state = f.state;
	for (size_t i = 0; i < 4; i++)
	{
		clone.points[i].x = f.points[i].x;
		clone.points[i].y = f.points[i].y;
	}
	return clone;
}

void clearFigure(Figure f) {
	SetColor(White, Black);
	for (size_t i = 0; i < 4; i++)
	{
		SetCursorPosition((f.points[i].x + 1) * 2, f.points[i].y + 1);
		cout << " ";
	}
}

void printFigure(Figure f) {
	drawField();
	SetColor(White, f.color);
	for (size_t i = 0; i < 4; i++)
	{
		SetCursorPosition((f.points[i].x + 1) * 2, f.points[i].y + 1);
		cout << "  ";
	}
	SetColor(White, Black);
}