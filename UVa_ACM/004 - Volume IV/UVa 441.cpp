#include <iostream>
#include <string>
using namespace std;

int a;
string n[14];

int re(int i,int j,string x) {
	if (j) {
		for (i;i<=a-1;i++) re(i+1,j-1,x+" "+n[i]);
	}
	else cout<<x.substr(1,x.size()-1)<<endl;
	return 0;
}

int main() {
	int i,t;
	for (t=0;cin>>a&&a;t++) {
		for (i=0;i<a;i++) cin>>n[i];
		if (t) cout<<endl;
		re(0,6,"");
	}
}