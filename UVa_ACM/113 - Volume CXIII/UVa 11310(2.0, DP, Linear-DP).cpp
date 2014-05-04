#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 50
long long dp[MAX];

int main()
{
	int i, t;
	dp[0] = dp[1] = 1, dp[2] = 5;
	for (i = 3; i < MAX; i++)
		dp[i] = dp[i - 1] + 4 * dp[i - 2] + 2 * dp[i - 3];
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d", &i);
		printf("%lld\n", dp[i]);
	}
}