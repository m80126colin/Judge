#include <iostream>
using namespace std;

int main() {
	unsigned long long a[101][101],i,j;
	memset(a,0,sizeof(a));
	for (i=1;i<=100;i++) {
		for (j=1;j<=i;j++) {
			if (j-1&&j+1<=i) a[i][j]+=a[i-1][j-1]+a[i-1][j];
			else if (j==1) a[i][j]=i;
			else a[i][j]=1;
		}
	}
	while (cin>>i>>j&&i&&j) cout<<i<<" things taken "<<j<<" at a time is "<<a[i][j]<<" exactly.\n";
}