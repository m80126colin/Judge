#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int t,n,s[1001],i,j;
	double a[1001];
	for (cin>>t;t;t--) {
		cin>>n;
		for (i=1;i<=n;i++) s[i]=0;
		for (i=1;i<=n;i++) {
			a[0]=0;
			for (j=1;j<=n;j++) {
				scanf("%lf",&a[j]);
				a[0]+=abs(a[j]);
			}
			for (j=1;j<=n;j++) {
				if (abs(a[j])>a[0]-abs(a[j])) {
					s[j]++;
					break;
				}
			}
		}
		for (i=1;i<=n;i++) {
			if (s[i]>1||s[i]==0) {
				cout<<"no"<<endl;
				n=0;
				break;
			}
		}
		if (n) cout<<"yes"<<endl;
	}
}