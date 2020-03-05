#include <stdio.h>
#include <string.h>
#include <iostream>
#define M 1010
#define pMAX 1000007
using namespace std;

int pas[M][M];

int main()
{
	int i, j;
	pas[1][1] = 1;
	for (i = 2; i <= 1000; i++)
		for (j = 1; j <= i; j++)
			pas[i][j] = (pas[i-1][j-1] + pas[i-1][j]) % pMAX;
	while (scanf("%d", &i) != EOF)
	{
		for (j = 1; j <= i + 1; j++)
		{
			if (j > 1) putchar(' ');
			printf("%d", pas[i + 1][j]);
		}
		puts("");
	}
}