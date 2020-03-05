#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	bool ox;
	int a[1001],n,i;
	while (cin>>n) {
		cout<<n<<"!\n";
		for (i=1000;i;i--) a[i]=0;
		a[1]=1;
		for (n;n;n--) {
			for (i=999;i;i--) {
				a[i]*=n;
				if (a[i]/100000) {
					a[i+1]+=a[i]/100000;
					a[i]%=100000;
				}
			}
		}
		for (i=1;i<=999;i++) {
			if (a[i]/100000) {
				a[i+1]+=a[i]/100000;
				a[i]%=100000;
			}
		}
		for (ox=0,i=1000;i;i--) {
			if (ox||i==1||(ox==0&&a[i])) {
				if (ox) cout<<setw(5)<<setfill('0')<<a[i];
				else {
					cout<<a[i];
					ox=1;
				}
			}
		}
		cout<<endl;
	}
}