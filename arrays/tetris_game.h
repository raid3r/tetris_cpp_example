#pragma once
#include <iostream>
#include "work_with_console.h"



//Structures
enum FigureType {
	T_FIGURE, I_FIGURE, O_FIGURE, L_FIGURE, J_FIGURE, S_FIGURE, Z_FIGURE
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
void drawFrame(int posX, int posY, int width, int height, ConsoleColor color);
void showMessage(std::string text, ConsoleColor textColor, ConsoleColor frameColor);

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
Figure initLFigure();
Figure initJFigure();
Figure initSFigure();
Figure initZFigure();

// Rotate
void rotate(Figure& f);
void rotateIFugure(Figure& f);
void rotateTFugure(Figure& f);
void rotateLFugure(Figure& f);
void rotateJFugure(Figure& f);
void rotateSFugure(Figure& f);
void rotateZFugure(Figure& f);

