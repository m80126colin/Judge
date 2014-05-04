#include <iostream>
#include <iomanip>
using namespace std;

static long long a[1001][258];

int main() {
	bool ox;
	long long n,i,j,t;
	memset(a,0,sizeof(a));
	a[0][1]=a[1][1]=1;
	for (i=2;i<=1000;i++) {
		t=0;
		for (j=1;j<258;j++) {
			a[i][j]=a[i-1][j]*i+t;
			t=a[i][j]/(long long) 1e10;
			a[i][j]%=(long long) 1e10;
		}
	}
	while (cin>>n) {
		cout<<n<<"!\n";
		for (ox=0,i=257;i;i--) {
			if (ox||i==1||(ox==0&&a[n][i])) {
				if (ox) cout<<setw(10)<<setfill('0')<<a[n][i];
				else {
					cout<<a[n][i];
					ox=1;
				}
			}
		}
		cout<<endl;
	}
}