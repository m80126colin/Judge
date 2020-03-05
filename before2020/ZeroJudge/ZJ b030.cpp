#include <iostream>
#include <string>
using namespace std;

int main() {
	bool ox_1,ox_2;
	int a[128],b[128],i;
	string n;
	while (getline(cin,n)) {
		ox_1=ox_2=1;
		for (i=127;i;i--) a[i]=b[i]=0;
		for (i=0;i<n.size();i++) a[n[i]]++;
		getline(cin,n);
		for (i=0;i<n.size();i++) b[n[i]]++;
		for (i=65;i<=90;i++) {
			if (a[i]!=b[i]) {
				ox_1=0;
				break;
			}
		}
		for (i=97;ox_1&&i<=122;i++) {
			if (a[i]!=b[i]) {
				ox_2=0;
				break;
			}
		}
		if (ox_1&&ox_2) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}