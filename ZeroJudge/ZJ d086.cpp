#include <iostream>
#include <string>
using namespace std;

int main() {
	bool ox;
	int t,i;
	string n;
	while (getline(cin,n)&&n!="0") {
		ox=1;
		for (i=t=0;i<n.size();i++) {
			if (n[i]>'z'||(n[i]<'a'&&n[i]>'Z')||n[i]<'A') {
				cout<<"Fail\n";
				ox=0;
				break;
			}
			else if (n[i]>='a'&&n[i]<='z') t+=n[i]-96;
			else t+=n[i]-64;
		}
		if (ox) cout<<t<<endl;
	}
}