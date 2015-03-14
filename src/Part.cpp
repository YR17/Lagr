#include <Part.h>
#include <iostream>
using namespace std;

Part::Part(){
	number = 1;
	pow = 0;
}

Part *Part::operator +(Part *ob){
	if(pow==ob->pow){
		Part *result = new Part;
		result->number = number + ob->number;
		return result;
	}
	else return NULL;
}

Part *Part::operator +(double num){
	if(pow==0){
		Part *result = new Part;
		result->pow = pow;
		result->number = number + num;
		return result;
	}
	else return NULL;
}

void Part::operator +=(Part *ob){
	if(pow==ob->pow){
		number+=ob->number;
	}
}

void Part::operator +=(double num){
	if(pow==0){
		number+=num;
	}
}

Part *Part::operator *(Part *ob){
	Part *result = new Part;
	result->pow = pow + ob->pow;
	result->number = number * ob->number;
	return result;
}

Part *Part::operator *(double num){
	Part *result = new Part;
	result->pow = pow;
	result->number = number * num;
}

void Part::operator *=(Part *ob){
	number*=ob->number;
	pow+=ob->pow;
}

void Part::operator *=(double num){
	number*=num;
}

void Part::operator -(){
	number=-number;
}

double Part::calculate(double num){
	for(int c=0;c<pow;c++){
		num*=num;
	}
	return num*number;
}