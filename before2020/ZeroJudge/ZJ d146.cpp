#include <iostream>
using namespace std;

int main() {
	int n,m,t,i,j,f[101],g[101];
	while (cin>>n>>m) {
		for (t=1;t<=n;t++) cin>>f[t];
		for (t=1;t<=m;t++) cin>>g[t];
		t=0;
		for (i=j=1;i<=n&&j<=m;) {
			if (g[j]<f[i]) {
				j++;
				t+=n-i+1;
			}
			else i++;
		}
		cout<<t<<endl;
	}
}