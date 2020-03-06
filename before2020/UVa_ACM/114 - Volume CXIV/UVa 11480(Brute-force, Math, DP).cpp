/**
 *  @judge UVa
 *  @id 11480
 *  @tag Brute force, Math, DP
 */
#include <stdio.h>
#include <iostream>
#define N 1000020
using namespace std;

long long dp[N];

int main()
{
	int i, j;
	dp[0] = 1;
	for (j = 1; j < 4; j++)
		for (i = j; i < N; i++)
			dp[i] += dp[i - j];
	for (i = 1; scanf("%d", &j), j; i++)
		printf("Case %d: %lld\n", i, (j < 6)? 0: dp[j - 6]);
}