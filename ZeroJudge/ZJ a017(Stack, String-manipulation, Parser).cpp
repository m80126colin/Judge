#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string s,t;
stringstream ss,tt;
int expression();

void get_token() {
	if (ss>>t) ;
	else t="";
}

int factor() {
	int res;
	if (t=="(") get_token(),res=expression();
	else {
		tt.clear();
		tt.str(t);
		tt>>res;
	}
	get_token();
	return res;
}

int term() {
	int res=factor();
	while (1) {
		if (t=="*") get_token(),res*=factor();
		else if (t=="/") get_token(),res/=factor();
		else if (t=="%") get_token(),res%=factor();
		else break;
	}
	return res;
}

int expression() {
	int res=term();
	while (1) {
		if (t=="+") get_token(),res+=term();
		else if (t=="-") get_token(),res-=term();
		else break;
	}
	return res;
}

int main() {
	while (getline(cin,s)) {
		ss.clear();
		ss.str(s);
		get_token();
		cout<<expression()<<endl;
	}
}