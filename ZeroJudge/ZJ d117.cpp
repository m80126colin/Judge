#include <iostream>
#include <string>
using namespace std;

int main() {
	bool ox;
	int m,i;
	string l;
	while (getline(cin,l)) {
		m=0;ox=1;
		for (i=0;i<l.size();i++) {
			if (l[i]>='a'&&l[i]<='z') m+=l[i]-96;
			if (l[i]>='A'&&l[i]<='Z') m+=l[i]-38;
		}
		for (i=2;i*i<=m;i++) {
			if (m%i==0) {
				ox=0;
				break;
			}
		}
		if (ox) cout<<"It is a prime word."<<endl;
		else cout<<"It is not a prime word."<<endl;
	}
}