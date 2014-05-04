#include <stdio.h>
int main() {
	long long t,n,b,k,sum,product,entry;
	for (scanf("%lld",&t);t;t--) {
		sum=0;
		for (scanf("%lld%lld",&n,&b);b;b--) {
			product=1;
			for (scanf("%lld",&k);k;k--) {
				scanf("%lld",&entry);
				product*=entry;
				product%=n;
			}
			sum+=product;
			sum%=n;
		}
		printf("%lld\n",sum);
	}
}