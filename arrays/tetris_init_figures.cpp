#include "tetris_game.h"

/*
  
  е
  е
  ее - L
   
   е
   е
  ее - J

  X
  XX
   X  - S

   X
  XX
  X   - Z
*/

Figure initTFigure() {
	Figure f;
	/*
	* 0123456 X
	0    XXX
	1     X
	Y
	*/
	f.points[0] = { 4,0 };
	f.points[1] = { 5,0 };
	f.points[2] = { 6,0 };
	f.points[3] = { 5,1 };
	f.color = Red;
	f.state = 1;
	f.type = T_FIGURE;
	return f;
}

Figure initIFigure() {
	Figure f;
	/*
	* 0123456 X
	0    XXX
	1     X
	Y
	*/
	f.points[0] = { 4,0 };
	f.points[1] = { 5,0 };
	f.points[2] = { 6,0 };
	f.points[3] = { 7,0 };
	f.color = Blue;
	f.state = 1;
	f.type = I_FIGURE;
	return f;
}

Figure initOFigure() {
	Figure f;
	/*
	* 0123456 X
	0     XX
	1     XX
	Y
	*/
	f.points[0] = { 4,0 };
	f.points[1] = { 5,0 };
	f.points[2] = { 4,1 };
	f.points[3] = { 5,1 };
	f.color = Yellow;
	f.state = 1;
	f.type = O_FIGURE;
	return f;
}

Figure initLFigure() {
	/*0123456
	0	X
	1	X
	2	XX
	*/
	Figure f;
	f.points[0] = { 2,0 };
	f.points[1] = { 2,1 };
	f.points[2] = { 2,2 };
	f.points[3] = { 3,2 };
	f.color = Green;
	f.state = 1;
	f.type = L_FIGURE;
	return f;
}

Figure initJFigure() {
	/*0123456
	0	 X
	1	 X
	2	XX
	*/
	Figure f;
	f.points[0] = { 3,0 };
	f.points[1] = { 3,1 };
	f.points[2] = { 3,2 };
	f.points[3] = { 2,2 };
	f.color = Magenta;
	f.state = 1;
	f.type = J_FIGURE;
	return f;
}

Figure initSFigure() {
	/*0123456
	0	X
	1	XX
	2	 X
	*/
	Figure f;
	f.points[0] = { 2,0 };
	f.points[1] = { 2,1 };
	f.points[2] = { 3,1 };
	f.points[3] = { 3,2 };
	f.color = White;
	f.state = 1;
	f.type = S_FIGURE;
	return f;
}

Figure initZFigure() {
	/*0123456
	0	 X
	1	XX
	2	X
	*/
	Figure f;
	f.points[0] = { 3,0 };
	f.points[1] = { 3,1 };
	f.points[2] = { 2,1 };
	f.points[3] = { 2,2 };
	f.color = Cyan;
	f.state = 1;
	f.type = Z_FIGURE;
	return f;
}


Figure getRandomFigure() {
	switch (rand() % 7)
	{
	case 0:
		return initTFigure();
	case 1:
		return initIFigure();
	case 2:
		return initOFigure();
	case 3:
		return initLFigure();
	case 4:
		return initJFigure();
	case 5:
		return initSFigure();
	case 6:
		return initZFigure();
	default:
		break;
	}
}
