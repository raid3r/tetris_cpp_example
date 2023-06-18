#include "tetris_game.h"


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


Figure getRandomFigure() {
	switch (rand() % 3)
	{
	case 0:
		//return initTFigure();
	case 1:
		return initIFigure();
	case 2: 
		return initOFigure();
	default:
		break;
	}
}



//TODO
//Figure initL1Figure() {
//	/*
//		X
//		X
//		XX
//	*/
//
//}7
//Figure initL2Figure() {
//	/*
//		XX
//		X
//		X
//	*/
//
//}
//Figure initOFigure() {
//	/*
//		XX
//		XX
//	*/
//	
//}
//Figure initS1Figure() {
//	/*
//		X
//		XX
//		 X
//	*/
//}
//Figure initS2Figure() {
//	/*
//		 X
//		XX
//		X
//	*/
//}
