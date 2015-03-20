#include <Equation.h>
using namespace std;

void Equation::clear(){
	parts.clear();
}

void Equation::resume(){
	vector<Part> buffer;
	int maxPow = 0;
	for(int c=0;c<parts.size();c++){
		if(maxPow<parts[c].pow){
			maxPow = parts[c].pow;
		}
	}
	int minPow = maxPow;
	for(int c=0;c<parts.size();c++){
		if(minPow>parts[c].pow){
			minPow = parts[c].pow;
		}
	}
	for(int c=maxPow;c>minPow-1;c--){
		Part buf;
		buf.pow = c;
		buf.number = 0;
		for(int c1=0;c1<parts.size();c1++){
			if(parts[c1].pow==c){
				buf += &parts[c1];
			}
		}
		buffer.push_back(buf);
	}
	parts = buffer;
}

void Equation::operator =(string str){
	clear();
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
	delete buffer;
}

void Equation::operator +=(Part *ob){
	parts.push_back(*ob);
}

void Equation::operator *=(Part *ob){
	for(int c=0;c<parts.size();c++){
		parts[c]*=ob;
	}
}

void Equation::operator +=(Equation *ob){
	for(int c=0;c<ob->size();c++){
		parts.push_back(*(*ob)[c]);
	}
}

void Equation::operator *=(Equation *ob){
	std::vector<Part> buffer;
	for(int c=0;c<parts.size();c++){
		for(int c1=0;c1<ob->size();c1++){
			buffer.push_back(*(parts[c]*(*ob)[c1]));
		}
	}
	parts = buffer;
}

Part *Equation::operator [](int positon){
	return &parts[positon];
}

int Equation::size(){
	return parts.size();
}

void Equation::debug(){
	for(int c=0;c<parts.size();c++){
		if(parts[c].number==0)continue;
		else if(c!=0)cout<<'+';
		if(parts[c].number==1&&parts[c].pow==0)cout<<1;
		if(parts[c].number!=1)cout<<parts[c].number;
		if(parts[c].pow==0){
			continue;
		}
		if(parts[c].pow==1){
			cout<<'x';
			continue;
		}
		cout<<"x^"<<parts[c].pow;
	}
	cout<<endl;
}

