#include "my_input.h"

int inputInt(string prompt) {
	cout << prompt;
	int value;
	cin >> value;
	return value;
}

float inputFloat(string prompt) {
	cout << prompt;
	float value;
	cin >> value;
	return value;
}