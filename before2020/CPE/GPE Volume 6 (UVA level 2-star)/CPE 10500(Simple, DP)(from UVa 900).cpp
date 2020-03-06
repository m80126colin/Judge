/**
 *  @judge CPE
 *  @id 10500
 *  @tag Simple, DP
 */
#include <stdio.h>
#include <iostream>
using namespace std;

long long dp[60];

int main()
{
	int i;
	dp[0] = dp[1] = 1;
	for (i = 2; i < 60; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	while (scanf("%d", &i), i)
		printf("%lld\n", dp[i]);
}