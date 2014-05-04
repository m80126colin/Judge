#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a[3],i,j,t;
	for (cin>>t,j=1;j<=t;j++) {
		for (i=0;i<3;i++) cin>>a[i];
		sort(a,a+3);
		cout<<"Case "<<j<<": "<<a[1]<<endl;
	}
}