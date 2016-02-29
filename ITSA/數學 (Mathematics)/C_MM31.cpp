#include <stdio.h>
int main() {
	int n;
	while (scanf("%d",&n)!=EOF) {
		n/=6;
		if (!(n&1)) n--;
		printf("%lld\n",(long long) (6+n*6)*(n+1)/4);
	}
}