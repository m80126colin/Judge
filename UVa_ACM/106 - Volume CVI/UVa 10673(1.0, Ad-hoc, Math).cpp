#include <stdio.h>
int main() {
	int t;
	long long x,k;
	for (scanf("%d",&t);t;t--) {
		scanf("%lld%lld",&x,&k);
		printf("%lld %lld\n",k-x%k,x%k);
	}
}