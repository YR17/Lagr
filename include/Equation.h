#ifndef LAGR_H
#define LAGR_H
#include <Part.h>
#include <vector>
#include <iostream>
#include <stdlib.h>


class Equation{
	std::vector<Part> parts;
public:
	Equation(){};
	void operator =(std::string);
	void operator =(double);
	Part *operator +(Part*) const;
	Part *operator +(double) const;
	void operator +=(Part*);
	void operator +=(double);
	Part *operator *(Part*) const;
	Part *operator *(double) const;
	void operator *=(Part*);
	void operator *=(double);
	void debug();
};
#endif