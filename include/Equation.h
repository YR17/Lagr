#ifndef LAGR_H
#define LAGR_H
#include <Part.h>
#include <vector>
#include <iostream>
#include <stdlib.h>

class Equation{
	std::vector<Part> parts;
	void clear();
public:
	void resume();
	Equation(){};
	void operator =(std::string);
	void operator +=(Part*);
	void operator *=(Part*);
	void operator +=(Equation*);
	void operator *=(Equation*);
	Part *operator [](int);
	int size();
	double calculate(double);
	void debug();
};
#endif