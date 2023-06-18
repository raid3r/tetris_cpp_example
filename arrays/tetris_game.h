#pragma once
#include <iostream>
#include "work_with_console.h"


enum FigureType {
	T_FIGURE, I_FIGURE
};

struct Point {
	int x;
	int y;
};

struct Figure {

	Point points[4];
	ConsoleColor color;
	int state;
	FigureType type;
};

struct FieldCell {
	bool full;
	ConsoleColor color;
};

const int FIELD_ROWS = 20;
const int FIELD_COLS = 10;

extern FieldCell field[FIELD_COLS][FIELD_ROWS];

void initFileld();

void drawFieldFrame();

void drawField();

bool canPlaceOnField(const Figure& f);

void putOnField(const Figure& f);

void rotateIFugure(Figure& f);
void rotateTFugure(Figure& f);


Figure cloneFigure(Figure f);

void rotate(Figure& f);
void moveLeft(Figure& f);
void moveRight(Figure& f);
void moveDown(Figure& f);
void clearFigure(Figure f);


Figure initTFigure();
Figure initIFigure();


void printFigure(Figure f);


Figure getRandomFigure();

void game();
