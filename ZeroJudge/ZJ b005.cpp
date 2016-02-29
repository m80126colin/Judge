#include <iostream>
using namespace std;

int main() {
	int n,i,j,k,a[101],b[101];
	while (cin>>n) {
		for (i=0;i<=n;i++) a[i]=b[i]=0; 
		for (i=1;i<=n;i++) {
			for (j=1;j<=n;j++) {
				cin>>k;
				a[i]+=k;
				b[j]+=k;
			}
		}
		for (k=1,i=j=0;k<=n;k++) {
			if (a[k]%2) {
				i++;
				a[0]=k;
			}
			if (b[k]%2) {
				j++;
				b[0]=k;
			}
		}
		if (i>1||j>1||i!=j) cout<<"Corrupt";
		if (i==0&&j==0) cout<<"OK";
		if (i==1&&j==1) cout<<"Change bit ("<<a[0]<<","<<b[0]<<")";
		cout<<endl;
	}
}