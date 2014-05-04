#include <stdio.h>
int main() {
	int n, i;
	while (scanf("%d",&n)!=EOF) {
		putchar('1');
		for (i = 2; i <= n; i++) {
			if (!(n%i)) printf(" %d",i);
		}
		puts("");
	}
}