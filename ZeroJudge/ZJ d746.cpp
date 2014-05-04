#include <iostream>
#include <stdio.h>
#define MAX 2147483647
using namespace std;

int pos[2][2], dp[2][2];

int main()
{
	int i, j, lay;
	int t, w, h;
	char ch;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d%d", &w, &h);
		memset(dp, 0, sizeof(dp));
		pos[0][0] = pos[0][1] = 0;
		dp[0][0] = dp[0][1] = 0;
		getchar();
		for (lay = i = 0; i < h; i++)
		{
			pos[1][0] = MAX, pos[1][1] = 0;
			for (j = 0; j < w; j++)
			{
				ch = getchar();
				if (!((ch - '0') & 1))
				{
					pos[1][0] = min(pos[1][0], j);
					pos[1][1] = max(pos[1][1], j);
				}
			}
			getchar();
			if (pos[1][0] != MAX)
			{
				lay = i;
				dp[1][1] = min(dp[0][0] + abs(pos[0][0] - pos[1][0]), dp[0][1] + abs(pos[0][1] - pos[1][0])) + pos[1][1] - pos[1][0];
				dp[1][0] = min(dp[0][0] + abs(pos[0][0] - pos[1][1]), dp[0][1] + abs(pos[0][1] - pos[1][1])) + pos[1][1] - pos[1][0];
				pos[0][0] = pos[1][0];
				pos[0][1] = pos[1][1];
				dp[0][0] = dp[1][0];
				dp[0][1] = dp[1][1];
			}
		}
		printf("%d\n", min(dp[0][0], dp[0][1]) + lay);
	}
}