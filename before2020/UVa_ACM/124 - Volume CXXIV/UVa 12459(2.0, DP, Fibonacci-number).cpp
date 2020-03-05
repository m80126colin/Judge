#include <stdio.h>
#include <iostream>
using namespace std;

unsigned long long dp[81];

int main()
{
	int n;
	dp[0] = dp[1] = 1;
	for (n = 2; n <= 80; n++)
		dp[n] = dp[n - 1] + dp[n - 2];
	while (scanf("%d", &n), n)
		printf("%llu\n", dp[n]);
}