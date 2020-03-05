#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int dp[25], i;
	dp[0] = 1, dp[1] = 1;
	for (i = 2; i < 25; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	while (cin >> i) cout << dp[i] << endl;
}