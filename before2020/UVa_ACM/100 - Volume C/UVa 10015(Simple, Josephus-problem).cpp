#include <stdio.h>
#include <string.h>
#include <iostream>
#define MAX 32610
#define pMAX 3502
using namespace std;

bool ox[MAX];
int p[pMAX], pr;
int dp[pMAX];

void sieve()
{
	int i, j;
	memset(ox, 0, sizeof(ox));
	ox[1] = 1;
	pr = 0;
	for (i = 2; i < MAX; i++)
	{
		if (!ox[i])
		{
			p[pr++] = i;
			for (j = 2; i * j < MAX; j++)
				ox[i * j] = 1;
		}
	}
	return;
}

int main()
{
	int n, i;
	sieve();
	while (scanf("%d",&n), n)
	{
		memset(dp, 0, sizeof(dp));
		dp[1] = 0;
		for (i = 2; i <= n; i++)
		{
			dp[i] = (dp[i - 1] + p[n - i]) % i;
		}
		printf("%d\n", dp[n] + 1);
	}
}