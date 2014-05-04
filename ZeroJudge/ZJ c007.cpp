#include <iostream>
#include <string>
using namespace std;

int main() {
	string a,b;
	int r,t;
	a="";
	while (getline(cin,b)) a+=b+'\n';
	t=1;
	for (r=0;r<a.size();r++) {
		if (a[r]=='\"') {
			if (t%2) cout<<"``";
			else cout<<"\'\'";
			t++;
		}
		else cout<<a[r];
	}
}