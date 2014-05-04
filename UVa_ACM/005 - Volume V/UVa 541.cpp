#include <iostream>
using namespace std;

int main() {
	int n,l[100],r[100],i,j,k,ox;
	while (cin>>n&&n) {
		ox=0;
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		for (i=1;i<=n;i++) {
			for (j=1;j<=n;j++) {
				cin>>k;
				l[i]+=k;
				r[j]+=k;
			}
		}
		i=j=0;
		for (k=1;k<=n;k++) {
			if (l[k]%2) {
				i++;
				l[0]=k;
			}
			if (r[k]%2) {
				j++;
				r[0]=k;
			}
		}
		if (i>1||j>1) cout<<"Corrupt\n";
		else if (i==1&&j==1) cout<<"Change bit ("<<l[0]<<","<<r[0]<<")\n";
		else cout<<"OK\n";
	}
}