/**
 *  @judge ZeroJudge
 *  @id d421
 *  @source UVa 332
 */
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

int i,j,a,b,t;
string n;
stringstream ss;

int re(int x,int y) {
	if (a) {
		if (y%x) re(y%x,x);
		else {
			a/=x;
			b/=x;
		}
	}
	return 0;
}

int main() {
	t=1;
	while (cin>>i&&i!=-1) {
		cin.ignore(3);
		cin>>n;
		ss.clear();
		ss.str(n);
		ss>>j;
		if (i&&j) {
			a=ceil((double) j-j/pow(10.0,i));
			i=n.size()-i;
			b=pow(10.0,(double) n.size())-pow(10.0,i);
		}
		else {
			a=j;
			if (a) b=pow(10.0,(double) n.size());
			else b=1;
		}
		re(a,b);
		cout<<"Case "<<t++<<": "<<a<<"/"<<b<<endl;
	}
}