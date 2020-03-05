#include <stdio.h>
#include <math.h>
int main() {
	int t;
	long long n,i;
	for (t=1;scanf("%lld",&n)&&n;t++) {
		i=(double)(3+sqrt((double)9+8*n))/2;
		while (i*(i-3)/2<n) i++;
		printf("Case %d: %lld\n",t,i);
	}
}