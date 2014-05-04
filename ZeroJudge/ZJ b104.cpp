#include <iostream>
#include <string>
using namespace std;

int main() {
	int n,a[128],b[128],i;
	string z;
	for (cin>>n,cin.ignore(1);n;n--) {
		for (i=0;i<128;i++) a[i]=b[i]=0;
		getline(cin,z);
		for (i=0;i<z.size();i++) a[z[i]]++;
		getline(cin,z);
		for (i=0;i<z.size();i++) b[z[i]]++;
		for (i=0;i<128;i++) {
			if (a[i]!=b[i]) {
				cout<<"impossible"<<endl;
				i=0;
				break;
			}
		}
		if (i) cout<<"possible"<<endl;
	}
}