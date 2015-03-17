#include <Equation.h>
using namespace std;

int main(){
	Equation x, x1;
	string s1, s2;
	cin>>s1;
	cin>>s2;
	x = s1;
	x1 = s2;
	x*=&x1;
	x.debug();
	x.resume();
	x.debug();
	return 0;
}