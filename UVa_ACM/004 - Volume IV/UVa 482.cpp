#include <iostream>
#include <string>
using namespace std;

int main() {
	static string n[500000];
	char a;
	static int b[500000],c,t;
	for (cin>>t;t;t--) {
		for (b[0]=1;b[0];b[0]++) {
			cin>>b[b[0]];
			cin.get(a);
			if (a=='\n') break;
		}
		for (c=1;c<=b[0];c++) cin>>n[b[c]];
		for (c=1;c<=b[0];c++) cout<<n[c]<<endl;
		if (t!=1) cout<<endl;
	}
}