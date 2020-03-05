#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	long long n, dp[60];
	dp[0] = dp[1] = 1;
	for (n = 2; n <= 50; n++)
		dp[n] = dp[n - 1] + dp[n - 2];
	while (scanf("%lld", &n), n)
		printf("%lld\n", dp[n]);
}