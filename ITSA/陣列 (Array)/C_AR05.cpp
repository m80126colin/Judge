#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	int a[24], n, i, s, d;
	scanf("%d", &n);
	memset(a, 0, sizeof(a));
	for (i = 0; i < n; i++) {
		scanf("%d%d", &s, &d);
		for (;s < d;s++) a[s]++;
	}
	for (i = 0; i < 24; i++) a[0] = max(a[0], a[i]);
	printf("%d\n", a[0]);
}