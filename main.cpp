#include <Equation.h>
using namespace std;

int main(){
	// Equation x;
	// cout<<"x+2x3+43x3+1234+x"<<endl;
	// x = "x+2x3+43x3+1234+x";
	// x.debug();
	Part p1, p2;
	p1.number = 2;
	p1.pow = 1;
	p2.number = 3;
	p2.pow = 1;
	cout<<(*(p1+&p2)).calculate(1.5)<<endl;
	return 0;
}