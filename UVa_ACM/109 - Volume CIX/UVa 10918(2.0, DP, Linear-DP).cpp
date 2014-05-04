#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 20
int dp[MAX], sum[MAX];

int main()
{
	int i, n;
	dp[0] = 1, sum[0] = 0;
	for (i = 1; i < MAX; i++)
	{
		dp[i] = (sum[i - 1] << 1) + 3 * dp[i - 1];
		sum[i] = sum[i - 1] + dp[i - 1];
	}
	while (scanf("%d", &n), n != -1)
		if (n & 1) puts("0");
		else printf("%d\n", dp[n >> 1]);
}