#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	int a[6], i;
	for (i = 0; i < 6; i++) scanf("%d", &a[i]);
	for (i = 1; i <= 6; i++) {
		printf("%d", a[6-i]);
		if (i < 6) putchar(' ');
	}
	puts("");
}