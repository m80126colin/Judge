#include <iostream>
using namespace std;

int main() {
	int n[10000],i,j,h;
	memset(n,0,sizeof(n));
	while (cin>>i>>h>>j) {
		for (i;i<j;i++) if (h>n[i]) n[i]=h;
	}
	cout<<1<<" "<<n[1];
	for (i=2;i<10000;i++) {
		if (n[i]!=n[i-1]) cout<<" "<<i<<" "<<n[i];
	}
	cout<<endl;
}