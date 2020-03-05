#include <stdio.h>
int main() {
	int i, a, b, n;
	while (scanf("%d%d%d", &a, &b, &n) != EOF) {
		printf("%d.", a / b);
		a %= b;
		for (i = 0; i < n; i++) {
			a *= 10;
			printf("%d", a / b);
			a %= b;
		}
		puts("");
	}
}