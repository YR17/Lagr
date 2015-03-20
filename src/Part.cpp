#include <Part.h>
#include <iostream>
using namespace std;

Part::Part(){
	number = 1;
	pow = 0;
	denominator = 1;
}

void Part::operator =(Part *ob){
	number = ob->number;
	pow = ob->pow;
	denominator = ob->denominator;
}

Part *Part::operator +(Part *ob){
	if(pow==ob->pow){
		Part *result = new Part;
		result->pow = pow;
		if(denominator==ob->denominator){
			result->denominator = denominator;
			result->number = number + ob->number;
		}
		else{
			result->denominator = denominator * ob->denominator;
			result->number = number * ob->denominator + ob->number * denominator;
			return result;
		}
		return result;
	}
	else return NULL;
}

Part *Part::operator +(double num){
	if(pow==0){
		Part *result = new Part;
		result->pow = pow;
		result->number += num * denominator;
		return result;
	}
	else return NULL;
}

void Part::operator +=(Part *ob){
	if(pow==ob->pow){
		if(denominator==ob->denominator)number+=ob->number;
		else{
			denominator *= ob->denominator;
			number = number * ob->denominator + ob->number * denominator;
		}
	}
}

void Part::operator +=(double num){
	if(pow==0){
		number+=num*denominator;
	}
}

Part *Part::operator *(Part *ob){
	Part *result = new Part;
	result->pow = pow + ob->pow;
	result->number = number * ob->number;
	result->denominator = denominator * ob->denominator;
	return result;
}

Part *Part::operator *(double num){
	Part *result = new Part;
	result->pow = pow;
	result->number = number * num;
	result->denominator = denominator;
}

void Part::operator *=(Part *ob){
	number*=ob->number;
	pow+=ob->pow;
	denominator *= ob->denominator;
}

void Part::operator *=(double num){
	number*=num;
}

void Part::operator -(){
	number=-number;
}

Part *Part::operator /(Part *ob){
	Part *buf = new Part;
	buf->denominator = ob->number;
	buf->pow = ob->pow;
	buf->number = ob->denominator;
	return *this * buf;
}

Part *Part::operator /(double num){
	if(num==0){
		cout<<"Error division on zero"<<endl;
	}
	Part *result = new Part;
	result = this;
	result->denominator *= num;
}

void Part::operator /=(Part *ob){
	Part *buffer = new Part;
	buffer->pow = ob->pow;
	buffer->number = ob->denominator;
	buffer->denominator = ob->number;
	*this *= buffer;
	delete buffer;	
}

void Part::operator /=(double num){
	if(num==0){
		cout<<"Error division on zero"<<endl;
	}
	denominator *= num;
}

double Part::calculate(double num){
	for(int c=0;c<pow;c++){
		num*=num;
	}
	return num*number/denominator;
}