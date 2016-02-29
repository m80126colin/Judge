#include <stdio.h>
#include <math.h>
int isprime(int x) {
	int d = sqrt((double) x), i;
	for (i=2;i<=d;i++) {
		if (!(x%i)) return 0;
	}
	return 1;
}
int main() {
	int n;
	while (scanf("%d",&n)!=EOF) {
		if (isprime(n)) puts("YES");
		else puts("NO");
	}
}