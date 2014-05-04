#include <iostream>
#include <string>
using namespace std;

int main() {
	int i,j;
	string n;
	while (getline(cin,n)) {
		for (j=n.size()-1,i=0;j>=0;j--) {
			if ((n[j]<'p'||n[j]>'z')&&n[j]!='N'&&n[j]!='C'&&n[j]!='D'&&n[j]!='E'&&n[j]!='I') {
				i=0;
				break;
			}
			if (n[j]>='p'&&n[j]<='z') i++;
			if (n[j]=='C'||n[j]=='D'||n[j]=='E'||n[j]=='I') {
				i-=2;
				if (i<0) break;
				else i++;
			}
			if (n[j]=='N') {
				i--;
				if (i<0) break;
				else i++;
			}
		}
		if (i==1) cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}
}