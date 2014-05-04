#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 10010
int a[MAX], dp[MAX], n, ans;

int main()
{
	int i;
	while (scanf("%d", &n), n)
	{
		dp[0] = 0;
		ans = -1;
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			if (dp[i - 1] + a[i] > 0)
			{
				dp[i] = dp[i - 1] + a[i];
				ans = max(ans, dp[i]);
			}
			else dp[i] = 0;
		}
		if (ans > 0) printf("The maximum winning streak is %d.\n", ans);
		else puts("Losing streak.");
	}
}