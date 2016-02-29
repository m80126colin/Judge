#include <iostream>
#include <string>
using namespace std;

int main() {
	bool ox;
	int i[128],j,k;
	string n;
	ox=0;
	while (getline(cin,n)&&!cin.eof()) {
		if (ox) cout<<endl;
		for (j=0;j<128;j++) i[j]=0;
		for (j=0;j<n.size();j++) i[n[j]]++;
		for (j=1;j<=1000;j++) {
			for (k=127;k>=0;k--) {
				if (i[k]==j) cout<<k<<" "<<i[k]<<endl;
				ox=1;
			}
		}
	}
}