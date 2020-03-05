#include <iostream>
#include <string>
using namespace std;

int main() {
	string z;
	int t,a,c[128],g;
	char b;
	cin>>t;
	for (a=1;a<=t;a++) {
		z="";
		for (g=127;g;g--) c[g]=0;
		if (a==1) cin.get(b);
		while (cin.get(b)) {
			if (b=='\n') break;
			else c[b]++;
		}
		for (g=1;g<128;g++) {
			if (c[g]) {
				for (c[0]=c[g]-1;c[0];c[0]--) {
					if (c[g]%c[0]==0) break;
				}
				if ((c[0]==1)&&(c[g]!=1)) {
					b=g;
					z+=b;
				}
			}
		}
		cout<<"Case "<<a<<": ";
		if (z!="") cout<<z<<endl;
		else cout<<"empty"<<endl;
	}
}