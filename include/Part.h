#ifndef PART_H
#define PART_H
#include <cstddef>
class Part{
public:
	double number;
	int pow;
	Part();
	Part *operator +(Part*);
	Part *operator +(double);
	void operator +=(Part*);
	void operator +=(double);
	Part *operator *(Part*);
	Part *operator *(double);
	void operator *=(Part*);
	void operator *=(double);
	double calculate(double);
};
#endif