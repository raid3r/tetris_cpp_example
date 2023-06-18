#include "tetris_game.h"

using namespace std;

void game() {
	initFileld();
	drawFieldFrame();
	drawField();
	Figure temp;

	while (true)
	{
		Figure f = getRandomFigure();

		int timerTime = 500;
		int timer = timerTime;
		int tick = 50;

		SetCursorPosition(15, 3);
		cout << "Points: " << points;

		printFigure(f);

		while (true)
		{
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
		SetCursorPosition(f.points[i].x + 1, f.points[i].y + 1);
		cout << " ";
	}
}

void printFigure(Figure f) {
	drawField();
	SetColor(White, f.color);
	for (size_t i = 0; i < 4; i++)
	{
		SetCursorPosition(f.points[i].x + 1, f.points[i].y + 1);
		cout << i;
	}
	SetColor(White, Black);
}