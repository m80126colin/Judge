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
		n--;
		while (n>=2) {
			if (isprime(n)) {
				printf("%d\n",n);
				break;
			}
			n--;
		}
		if (n<2) puts("1");
	}
}