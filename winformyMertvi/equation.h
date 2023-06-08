#pragma once
#include <cmath>
#include <string.h>
#include <sstream>
#include <iostream>
#include <iomanip>

class Equation {
	double a, b, c, root1, root2;
public:
	Equation(double a, double b, double c) : a(a), b(b), c(c) {}
	void calculate();
	double getRoot1();
	double getRoot2();
};