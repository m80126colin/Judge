#include <iostream>
#include <string>
using namespace std;

int main() {
	int n,m,i,j,k,b[23][23],t;
	string a[23];
	cin>>n>>m;
	for(t=1;n;t++) {
		for (i=22;i;i--) {
			for (j=22;j;j--) {
				b[i][j]=10000000;
			}
		}
		for (i=1;i<=n;i++) cin>>a[i];
		while (m--) {
			cin>>i>>j>>k;
			b[i][j]=k;
			b[j][i]=k;
		}
		for (k=1;k<=n;k++) {
			for (i=1;i<=n;i++) {
				for (j=1;j<=n;j++) b[i][j]=min(b[i][j],b[i][k]+b[k][j]);
			}
		}
		m=1;
		for (i=1;i<=n;i++) {
			b[i][i]=0;
			b[i][0]=0;
			for (j=1;j<=n;j++) b[i][0]+=b[i][j];
			if (b[i][0]<b[m][0]) m=i;
		}
		cout<<"Case #"<<t<<" : "<<a[m]<<endl;
		cin>>n>>m;
	}
}