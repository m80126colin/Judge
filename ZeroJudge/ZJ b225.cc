#include <iostream>
using namespace std;

int main() {
	int x[3],y[3],t,i;
	for (cin>>t;t;t--) {
		for (i=0;i<3;i++) cin>>x[i]>>y[i];
		if ((x[1]-x[0])*(y[2]-y[1])==(x[2]-x[1])*(y[1]-y[0])) cout<<"NO\n";
		else cout<<"YES\n";
	}
}