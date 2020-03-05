#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 9

int main() {
	int i, j, t, a[MAX][MAX];
	for (scanf("%d", &t); t; t--)
	{
		for (i = 0; i < MAX; i += 2)
			for (j = 0; j <= i; j += 2)
				scanf("%d", &a[i][j]);
		for (i = 2; i < MAX; i += 2)
			for (j = 1; j <= i; j += 2)
				a[i][j] = (a[i - 2][j - 1] - a[i][j - 1] - a[i][j + 1]) / 2;
		for (i = 1; i < MAX; i += 2)
			for (j = 0; j <= i; j++)
				a[i][j] = a[i + 1][j] + a[i + 1][j + 1];
		for (i = 0; i < MAX; i++)
		{
			for (j = 0; j <= i; j++)
			{
				printf("%d", a[i][j]);
				if (i != j) putchar(' ');
			}
			puts("");
		}
	}
}