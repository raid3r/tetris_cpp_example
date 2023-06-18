#include "tetris_game.h"


void moveLeft(Figure& f) {
	for (size_t i = 0; i < 4; i++)
	{
		f.points[i].x--;
	}
}

void moveRight(Figure& f) {
	for (size_t i = 0; i < 4; i++)
	{
		f.points[i].x++;
	}
}

void moveDown(Figure& f) {
	for (size_t i = 0; i < 4; i++)
	{
		f.points[i].y++;
	}
}

void rotate(Figure& f) {
	switch (f.type)
	{
	case T_FIGURE:
		rotateIFugure(f);
		break;
	case I_FIGURE:
		rotateIFugure(f);
		break;
	case O_FIGURE:
		break;
	default:
		break;
	}
}


void rotateIFugure(Figure& f) {
	switch (f.state)
	{
	case 1:
		f.points[0].x++;
		f.points[0].y--;

		f.points[2].x--;
		f.points[2].y++;

		f.points[3].x -= 2;
		f.points[3].y += 2;

		f.state = 2;
		break;
	case 2:
		/*
		0
		0123
		2
		3
		*/
		f.points[0].x--;
		f.points[0].y++;

		f.points[2].x++;
		f.points[2].y--;

		f.points[3].x += 2;
		f.points[3].y -= 2;
		f.state = 1;
		break;

	default:
		break;
	}
}

//TODO states
void rotateTFugure(Figure& f) {
	/*
	* 1
	012
	3
	2
	0
	31
	2
	3
	3
	210
	4
	0
	13
	2
	*/
	switch (f.state)
	{
	case 1:
		f.points[0].x++;
		f.points[1].y++;
		f.points[2].x--;
		f.points[2].y += 2;
		f.points[3].x--;
		f.state = 2;
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	default:
		break;
	}
}

// TODO other figures rotate