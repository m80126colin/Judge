/**
 *  @judge UVa
 *  @id 11296
 *  @tag Simple, DP, Coin changing
 */
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 1000010
long long DP[MAX];
int c[3] = {1, 2, 2};

int main()
{
	int i, j, n;
	DP[0] = 1;
	for (i = 0; i < 3; i++)
		for (j = c[i]; j < MAX; j++)
			DP[j] += DP[j - c[i]];
	while (scanf("%d", &n) != EOF)
		printf("%lld\n", DP[n]);
}