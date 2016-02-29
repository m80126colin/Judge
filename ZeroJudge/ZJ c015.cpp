#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string a,b;
unsigned int x,y,t;

int re() {
	stringstream ss;
	bool ox;
	int i;
	ox=0;
	b="";
	for (i=1;i<=a.size();i++) b+=a[a.size()-i];
	ss.clear();
	ss.str(a);
	ss>>x;
	ss.clear();
	ss.str(b);
	ss>>y;
	x+=y;
	ss.clear();
	ss<<x;
	a=ss.str();
	t++;
	for (i=0;i<=a.size()/2;i++) {
		if (a[i]!=a[a.size()-1-i]) {
			ox=1;
			break;
		}
	}
	if (ox) re();
	return 0;
}

int main() {
	unsigned int n;
	for (cin>>n;n;n--) {
		t=0;
		cin>>a;
		re();
		cout<<t<<" "<<a<<endl;
	}
}