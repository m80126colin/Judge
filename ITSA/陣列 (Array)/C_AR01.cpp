#include <stdio.h>
#include <iostream>
#define MAX 10010
using namespace std;

int main()
{
	int a[MAX], n, i;
	char ch;
	for (n = 0; scanf("%d", &a[n]) != EOF;) {
		n++;
		scanf("%c", &ch);
		if (ch == '\n') {
			for (i = 1; i <= n; i++) {
				printf("%d", a[n - i]);
				if (i != n) putchar(' ');
			}
			puts("");
			n = 0;
		}
	}
}