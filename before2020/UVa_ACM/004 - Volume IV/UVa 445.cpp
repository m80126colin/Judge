#include <iostream>
#include <string>
using namespace std;

int main() {
	int i,j;
	string n;
	while (getline(cin,n)) {
		if (n=="") cout<<endl;
		else {
			for (i=j=0;i<n.size();i++) {
				if (n[i]=='!') cout<<endl;
				if (n[i]>='0'&&n[i]<='9') j+=n[i]-48;
				if ((n[i]>='A'&&n[i]<='Z')||n[i]=='*') {
					for (;j;j--) cout<<n[i];
				}
				if (n[i]=='b') {
					for (;j;j--) cout<<" ";
				}
			}
			cout<<endl;
		}
	}
}