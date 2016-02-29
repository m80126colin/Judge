#include <iostream>
#include <string>
using namespace std;

int main() {
	string n;
	int t,i,blank;
	while (getline(cin,n)) {
		t=0;
		blank=1;
		for (i=0;i<n.size();i++) {
			if ((n[i]>='A'&&n[i]<='Z')||(n[i]>='a'&&n[i]<='z')) {
				t+=blank;
				blank=0;
			}
			else blank=1;
		}
		cout<<t<<endl;
	}
}