#include <iostream>
using namespace std;

int main() {
	int n,m,i,j,t;
	static unsigned long long a[1000001],b[1000001];
	for (cin>>n>>m;n;n--) {
		t=0;
		for (i=1;i<=m;i++) scanf("%lld",&a[i]);
		for (i=1;i<=m;i++) scanf("%lld",&b[i]);
		for (i=j=1;i<=m;i++) {
			while (a[i]>b[j]&&j<=m) j++;
			if (a[i]==b[j]) t++;
		}
		printf("%d\n",t);
	}
}