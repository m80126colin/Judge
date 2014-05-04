#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	bool ox;
	string n,a;
	stringstream ss,aa;
	int i,t;
	while (getline(cin,n)) {
		t=0;
		ss.clear();
		ss.str(n);
		while (ss>>a) {
			ox=1;
			for (i=0;i<a.size();i++) {
				if (a[i]>'9'||a[i]<'0') {
					ox=0;
					break;
				}
			}
			if (ox) {
				aa.clear();
				aa<<a;
				aa>>i;
				t+=i;
			}
		}
		cout<<t<<endl;
	}
}