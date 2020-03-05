#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	bool ox;
	static int a[3000],i,j,n;
	while (cin>>n) {
		for (i=0;i<3000;i++) a[i]=0;
		for (i=1;i<=n;i++) {
			a[0]+=n-i+1;
			for (j=2998;j>=0;j--) {
				a[j]*=i;
				if (a[j]/10000) {
					a[j+1]+=a[j]/10000;
					a[j]%=10000;
				}
			}
		}
		for (j=0;j<2999;j++) {
				if (a[j]/10000) {
					a[j+1]+=a[j]/10000;
					a[j]%=10000;
				}
			}
		for (ox=0,j=2999;j>=0;j--) {
			if ((ox==0&&a[j])||ox||j==0) {
				if (ox) cout<<setfill('0')<<setw(4)<<a[j];
				else cout<<a[j];
				ox=1;
			}
		}
		cout<<endl;
	}
}
