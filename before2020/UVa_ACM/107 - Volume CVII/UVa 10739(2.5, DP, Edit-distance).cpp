/**
 *  @judge UVa
 *  @id 10739
 *  @tag 2.5, DP, Edit distance
 */
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 1010
#define HASH(x) ((x) & 1)
char str[MAX];
int dp[MAX][MAX], len;

int main()
{
	int t, cnt, step, j;
	scanf("%d", &t);
	getchar();
	for (cnt = 1; cnt <= t; cnt++)
	{
		gets(str);
		len = strlen(str);
		memset(dp, 0, sizeof(dp));
		for (step = 2; step <= len; step++)
			for (j = 0; j + step <= len; j++)
				if (str[j] == str[j + step - 1])
					dp[j][j + step] = dp[j + 1][j + step - 1];
				else dp[j][j + step] = min(dp[j + 1][j + step], min(dp[j][j + step - 1], dp[j + 1][j + step - 1])) + 1;
		printf("Case %d: %d\n", cnt, dp[0][len]);
	}
}