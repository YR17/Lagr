#include <Equation.h>
using namespace std;



void Equation::operator =(string str){
	vector<string> *buffer = new vector<string>;
	int prevPos = 0;
	for(int c=0;c<str.length();c++){
		if(str[c]=='+'||str[c]=='-'||
			 str[c]=='*'||str[c]=='/'){
			if(c-prevPos<1){
				cout<<"Error "<<prevPos<<endl;
				exit(0);
			}
			buffer->push_back(str.substr(prevPos, c-prevPos));
		prevPos = c+1;
		}
	}
	if(str.length()-prevPos<1){
		cout<<"Error "<<prevPos<<endl;
		exit(0);
	}
	buffer->push_back(str.substr(prevPos, str.length()-prevPos));
	for(int c=0;c<buffer->size();c++){
		int pos=-1;
		for(int c1=0;c1<(*buffer)[c].length();c1++){
			if((*buffer)[c][c1]=='x'){
				pos = c1;
				break;
			}
		}
		Part buf;
		if(pos==-1){
			buf.number = atof((*buffer)[c].c_str());
		}
		else if(pos==0){
			int p;
			p = atof((*buffer)[c].substr(1).c_str());
			if(p==0)p++;
			buf.pow = p;
		}
		else{
			buf.number = atof((*buffer)[c].substr(0, pos).c_str());
			buf.pow = atof((*buffer)[c].substr(pos+1).c_str());
		}
		parts.push_back(buf);
	}
}

void Equation::debug(){
	for(int c=0;c<parts.size();c++){
		cout<<parts[c].number<<'\t'<<parts[c].pow<<endl;
	}
}