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
		rotateTFugure(f);
		break;
	case I_FIGURE:
		rotateIFugure(f);
		break;
	case O_FIGURE:
		break;
	case L_FIGURE:
		rotateLFugure(f);
		break;
	case J_FIGURE:
		rotateJFugure(f);
		break;
	case S_FIGURE:
		rotateSFugure(f);
		break;
	case Z_FIGURE:
		rotateZFugure(f);
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

void rotateTFugure(Figure& f) {
	/*
	*
	*
	*
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
		f.points[0].x++;
		f.points[0].y++;
		f.points[2].x--;
		f.points[2].y--;
		f.points[3].x++;
		f.points[3].y--;
		f.state = 3;
		break;
	case 3:
		f.points[0].x--;
		f.points[0].y++;
		f.points[2].x++;
		f.points[2].y--;
		f.points[3].x++;
		f.points[3].y++;
		f.state = 4;
		break;
	case 4:
		f.points[0].x--;
		f.points[0].y -= 2;
		f.points[1].y--;
		f.points[2].x++;
		f.points[3].x--;
		f.state = 1;
		break;
	default:
		break;
	}
}

void rotateLFugure(Figure& f) {
	switch (f.state)
	{
	case 1:
		f.points[0].x++;
		f.points[0].y++;
		f.points[2].x--;
		f.points[2].y--;
		f.points[3].x -= 2;
		f.state = 2;
		break;
	case 2:
		f.points[0].x--;
		f.points[0].y++;
		f.points[2].x++;
		f.points[2].y--;
		f.points[3].y -= 2;
		f.state = 3;
		break;
	case 3:
		f.points[0].x--;
		f.points[0].y--;
		f.points[2].x++;
		f.points[2].y++;
		f.points[3].x += 2;
		f.state = 4;
		break;
	case 4:
		f.points[0].x++;
		f.points[0].y--;
		f.points[2].x--;
		f.points[2].y++;
		f.points[3].y += 2;
		f.state = 1;
		break;
	default:
		break;
	}
}

void rotateJFugure(Figure& f) {
	switch (f.state)
	{
	case 1:
		f.points[0].x++;
		f.points[0].y++;
		f.points[2].x--;
		f.points[2].y--;
		f.points[3].y -= 2;
		f.state = 2;
		break;
	case 2:
		f.points[0].x--;
		f.points[0].y++;
		f.points[2].x++;
		f.points[2].y--;
		f.points[3].x += 2;
		f.state = 3;
		break;
	case 3:
		f.points[0].x--;
		f.points[0].y--;
		f.points[2].x++;
		f.points[2].y++;
		f.points[3].y += 2;
		f.state = 4;
		break;
	case 4:
		f.points[0].x++;
		f.points[0].y--;
		f.points[2].x--;
		f.points[2].y++;
		f.points[3].x -= 2;
		f.state = 1;
		break;
	default:
		break;
	}
}

void rotateSFugure(Figure& f) {
	switch (f.state)
	{
	case 1:
		f.points[0].x++;
		f.points[0].y++;
		f.points[2].x--;
		f.points[2].y++;
		f.points[3].x -= 2;
		f.state = 2;
		break;
	case 2:
		f.points[0].x--;
		f.points[0].y++;
		f.points[2].x--;
		f.points[2].y--;
		f.points[3].y -= 2;
		f.state = 3;
		break;
	case 3:
		f.points[0].x--;
		f.points[0].y--;
		f.points[2].y--;
		f.points[2].x++;
		f.points[3].x += 2;
		f.state = 4;
		break;
	case 4:
		f.points[0].x++;
		f.points[0].y--;
		f.points[2].y++;
		f.points[2].x++;
		f.points[3].y += 2;
		f.state = 1;
	default:
		break;
	}
}

void rotateZFugure(Figure& f) {
	switch (f.state)
	{
	case 1:
		f.points[0].y += 2;
		f.points[1].y++;
		f.points[1].x--;
		f.points[3].x--;
		f.points[3].y--;
		f.state = 2;
		break;
	case 2:
		f.points[0].x -= 2;
		f.points[1].y--;
		f.points[1].x--;
		f.points[3].x++;
		f.points[3].y--;
		f.state = 3;
		break;
	case 3:
		f.points[0].y -= 2;
		f.points[1].y--;
		f.points[1].x++;
		f.points[3].x++;
		f.points[3].y++;
		f.state = 4;
		break;
	case 4:
		f.points[0].x += 2;
		f.points[1].y++;
		f.points[1].x++;
		f.points[3].x--;
		f.points[3].y++;
		f.state = 1;
	default:
		break;
	}
}