#include <iostream>
#include <string>
using namespace std;

int main() {
	bool ox;
	string n;
	int a,t;
	while (cin>>n) {
		ox=1;
		t=n.size()/2;
		for (a=0;a<=t;a++) {
			if (n[a]!=n[n.size()-a-1]) {
				ox=0;
				break;
			}
		}
		if (ox) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}