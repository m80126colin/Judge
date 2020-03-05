#include <stdio.h>
int main() {
	int n;
	while (scanf("%d",&n)!=EOF) {
		n/=3;
		printf("%lld\n",(long long) (3 + n*3) * n / 2);
	}
}