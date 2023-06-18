#include "tetris_game.h"

using namespace std;

void initFileld() {
	for (size_t x = 0; x < FIELD_COLS; x++)
	{
		for (size_t y = 0; y < FIELD_ROWS; y++)
		{
			field[x][y].full = false;
			field[x][y].color = Black;
		}
	}
}

void drawFieldFrame() {
	for (size_t x = 0; x < FIELD_COLS + 2; x++)
	{
		for (size_t y = 0; y < FIELD_ROWS + 2; y++) {
			if (x == 0 || x == FIELD_COLS + 1 || y == FIELD_ROWS + 1) {
				SetCursorPosition(x, y);
				SetColor(White, DarkGray);
				cout << " ";
			}
		}
	}
	SetColor(White, Black);
}

void drawField() {
	for (size_t x = 0; x < FIELD_COLS; x++)
	{
		for (size_t y = 0; y < FIELD_ROWS; y++) {
			if (field[x][y].full) {
				SetColor(White, field[x][y].color);

			}
			else {
				SetColor(White, Black);
			}
			SetCursorPosition(x + 1, y + 1);
			cout << " ";
		}
	}
	SetColor(White, Black);
}

bool canPlaceOnField(const Figure& f) {

	for (size_t i = 0; i < 4; i++)
	{
		if (f.points[i].x < 0 || f.points[i].x >= FIELD_COLS ||
			f.points[i].y < 0 || f.points[i].y >= FIELD_ROWS) {
			return false;
		}
		if (field[f.points[i].x][f.points[i].y].full) {
			return false;
		}
	}
	return true;
}

void putOnField(const Figure& f) {
	for (size_t i = 0; i < 4; i++)
	{
		field[f.points[i].x][f.points[i].y].full = true;
		field[f.points[i].x][f.points[i].y].color = f.color;
	}
}
