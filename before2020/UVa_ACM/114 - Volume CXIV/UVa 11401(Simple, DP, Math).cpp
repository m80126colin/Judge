#include <stdio.h>
#include <string.h>
#include <iostream>
#define N 1000010
using namespace std;

long long dp[N];

int main()
{
	int n;
	//freopen("UVa_11401.txt", "w+", stdout);
	memset(dp, 0, sizeof(dp));
	for (n = 4; n < N; n++)
		dp[n] = dp[n - 1] + (long long) ((n - 1) / 2) * ((n - 2) / 2); // n - 1, 1 ; n - 2, 1 ; ... ; 2, 1 (n - 2 times); n - 2, 2 ; ... ; 3, 2 (n - 4 times);
	// d = -2, n = (n - 1) / 2, a*n - n*(n-1);
	while (scanf("%d", &n), n >= 3)
	{
		printf("%llu\n", dp[n]);
	}
}