#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

char table[5] = " .xW";
int dna[10], dp[2][50];

inline void change(int a, int b)
{
	dp[a][b] = dna[dp[!a][b - 1] + dp[!a][b] + dp[!a][b + 1]];
	return ;
}

inline void print(int *a)
{
	int i;
	for (i = 1; i <= 40; i++)
		putchar(table[a[i]]);
	puts("");
	return ;
}

int main()
{
	int t, i, j;
	for (scanf("%d", &t); t; t--)
	{
		for (i = 0; i < 10; i++) scanf("%d", &dna[i]);
		memset(dp, 0, sizeof(dp));
		dp[0][20] = 1;
		print(dp[0]);
		for (i = 1; i < 50; i++)
		{
			for (j = 1; j <= 40; j++)
				change(i & 1, j);
			print(dp[i & 1]);
		}
		if (t > 1) puts("");
	}
}