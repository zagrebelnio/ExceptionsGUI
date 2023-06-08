#include "equation.h"

void Equation::calculate() {
	double D = b * b - 4 * a * c;
	if (D < 0) {
		root1 = root2 = NAN;
	}
	else if (D == 0) {
		root1 = root2 = -b / (2 * a);
	}
	else {
		root1 = (-b + sqrt(D)) / (2 * a);
		root2 = (-b - sqrt(D)) / (2 * a);
	}
}

double Equation::getRoot1() {
	return root1;
}

double Equation::getRoot2() {
	return root2;
}