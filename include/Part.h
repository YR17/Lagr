#ifndef PART_H
#define PART_H
class Part{
public:
	double number;
	int pow;
	Part();
	Part *operator +(Part*) const;
	Part *operator +(double) const;
	void operator +=(Part*);
	void operator +=(double);
	Part *operator *(Part*) const;
	Part *operator *(double) const;
	void operator *=(Part*);
	void operator *=(double);
	double calculate(double);
};
#endif