#pragma once
#include <iostream>
#include "work_with_console.h"


//Structures
enum FigureType {
	T_FIGURE, I_FIGURE, O_FIGURE
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

//Constants
const int FIELD_ROWS = 20;
const int FIELD_COLS = 10;

//Global
extern FieldCell field[FIELD_COLS][FIELD_ROWS];
extern int points;

void game();

//Field
void initFileld();
void drawFieldFrame();
void drawField();
bool canPlaceOnField(const Figure& f);
void putOnField(const Figure& f);
void replaceWithUpperRow(const int y);
void clearRows();

// Tools
Figure cloneFigure(Figure f);
void clearFigure(Figure f);
void printFigure(Figure f);

// Move
void moveLeft(Figure& f);
void moveRight(Figure& f);
void moveDown(Figure& f);

// Init
Figure getRandomFigure();
Figure initTFigure();
Figure initIFigure();
Figure initOFigure();

// Rotate
void rotate(Figure& f);
void rotateIFugure(Figure& f);
void rotateTFugure(Figure& f);


