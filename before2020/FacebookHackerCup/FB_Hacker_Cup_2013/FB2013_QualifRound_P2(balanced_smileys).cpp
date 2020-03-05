#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 110
int dp[MAX][MAX], t, cnt, len;
char str[MAX];

int main()
{
	freopen("balanced_smileystxt.txt", "r", stdin);
	freopen("balanced_smileystxt.out", "w+", stdout);
	int i, j;
	scanf("%d", &t);
	getchar();
	for (cnt = 1; cnt <= t; cnt++)
	{
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		gets(str);
		len =strlen(str);
		for (i = 0; i < len; i++)
		{
			for (j = 0; j < len; j++)
			{
				if (dp[i][j])
				{
					if (str[i] == '(')
					{
						if (j < len) dp[i + 1][j + 1] = 1;
						if (i && str[i - 1] == ':') dp[i + 1][j] = 1;
					}
					else if (str[i] == ')')
					{
						if (j > 0) dp[i + 1][j - 1] = 1;
						if (i && str[i - 1] == ':') dp[i + 1][j] = 1;
					}
					else dp[i + 1][j] = 1;
				}
			}
		}
		printf("Case #%d: ", cnt);
		if (dp[len][0]) puts("YES");
		else puts("NO");
	}
}