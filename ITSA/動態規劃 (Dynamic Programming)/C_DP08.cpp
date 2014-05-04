#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int dp[15001] = {0}, i, j, c[4] = {1, 5, 10, 50};
	for (dp[0] = 1, i = 0; i < 4; i++)
		for (j = c[i]; j <= 15000; j++)
			dp[j] += dp[j - c[i]];
	while (scanf("%d", &i) != EOF)
		printf("%d\n", dp[i]);
}