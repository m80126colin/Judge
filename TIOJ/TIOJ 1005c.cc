#include <stdio.h>
#include <math.h>
int gcd(int x,int y) {
	if (x%y) return gcd(y,x%y);
	else return y;
}
int main() {
	int i,j,n,est,arr[50];
	while (scanf("%d",&n),n) {
		for (i=1;i<=n;i++) scanf("%d",&arr[i]);
		for (est=0,i=1;i<n;i++) {
			for (j=i+1;j<=n;j++) {
				if (gcd(arr[i],arr[j])==1) est++;
			}
		}
		if (!est) puts("No estimate for this data set.");
		else printf("%lf\n",sqrt((double) n*(n-1)*3.0/est) );
	}
}