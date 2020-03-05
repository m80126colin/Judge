#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 110
int dp[MAX];

int main()
{
	int i;
	dp[0] = dp[1] = 1, dp[2] = 2;
	for (i = 3; i < MAX; i++)
		dp[i] = dp[i - 2] + dp[i - 3];
	while (scanf("%d", &i) != EOF)
		printf("%d\n", dp[i]);
}