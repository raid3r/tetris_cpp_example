#include <iostream>
#include <conio.h>
#include "my_input.h"
#include "work_with_console.h"
#include "tetris_game.h"

using namespace std;

FieldCell field[FIELD_COLS][FIELD_ROWS];
int points = 0;

void main() {
	ShowConsoleCursor(false);
	srand(time(NULL));
	game();
}