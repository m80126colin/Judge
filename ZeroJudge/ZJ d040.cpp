#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int n,a[2],b[2],i,j;
	double s;
	while (cin>>n&&n) {
		s=0;
		for (i=1;i<=n;i++) {
			scanf("%d %d",&a[0],&b[0]);
			a[1]=max(a[0],b[0]);
			b[1]=min(a[0],b[0]);
			if (a[1]>=b[1]*4) {
				if (b[1]>s) {
					s=b[1];
					j=i;
				}
			}
			else if (a[1]>b[1]*2) {
				if ((double) a[1]/4>s) {
					s=(double) a[1]/4;
					j=i;
				}
			}
			else {
				if ((double) b[1]/2>s) {
					s=(double) b[1]/2;
					j=i;
				}
			}
		}
		printf("%d\n",j);
	}
}