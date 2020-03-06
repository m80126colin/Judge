/**
 *  @judge UVa
 *  @id 164
 *  @tag 3.0, DP, Edit distance
 */
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

#define MAX 30
string s1, s2;
int dp[MAX][MAX], path[MAX][MAX], del, ins;

void DP()
{
	int i, j;
	memset(dp, 0,sizeof(dp));
	dp[0][0] = path[0][0] = 0;
	for (i = 0; i < s1.size(); i++) /* delete head */
	{
		dp[i + 1][0] = dp[i][0] + 1;
		path[i + 1][0] = 1; /* delete */
	}
	for (j = 0; j < s2.size(); j++) /* insert head */
	{
		dp[0][j + 1] = dp[0][j] + 1;
		path[0][j + 1] = 2; /* insert */
	}
	for (i = 0; i < s1.size(); i++)
		for (j = 0; j < s2.size(); j++)
		{
			dp[i + 1][j + 1] = min(min(dp[i][j + 1], dp[i + 1][j]) + 1, dp[i][j] + (s1[i] != s2[j]));
			if (dp[i + 1][j + 1] == dp[i][j + 1] + 1)		/* delete */
				path[i + 1][j + 1] = 1;
			else if (dp[i + 1][j + 1] == dp[i + 1][j] + 1)	/* insert */
				path[i + 1][j + 1] = 2;
			else if (dp[i + 1][j + 1] == dp[i][j] + 1)		/* change */
				path[i + 1][j + 1] = 3;
			else path[i + 1][j + 1] = 4;
		}
	/*for (i = 0; i <= s1.size(); i++)
	{
		for (j = 0; j <= s2.size(); j++)
			printf(" %d", path[i][j]);
		puts("");
	}*/
	return ;
}

void print(int x, int y)
{
	if (x == 0 && y == 0)
		return ;
	if (path[x][y] == 1) /* delete */
	{
		print(x - 1, y);
		printf("D%c%02d", s1[x - 1], x + ins - del);
		del++;
	}
	else if (path[x][y] == 2)
	{
		print(x, y - 1);
		/* puts("\n");
		printf("x - 1: %d, y - 1: %d\n", x - 1, y - 1);
		printf("insert s1[x - 1]: %c, s2[y - 1]: %c\n", s1[x - 1], s2[y - 1]);
		printf("del: %d, ins: %d\n", del, ins);
		puts("\n"); */
		printf("I%c%02d", s2[y - 1], x + ins - del + 1);
		ins++;
	}
	else
	{
		print(x - 1, y - 1);
		if (path[x][y] == 3) printf("C%c%02d", s2[y - 1], x + ins - del);
	}
}

int main()
{
	while (cin >> s1, s1 != "#")
	{
		cin >> s2;
		DP();
		del = ins = 0;
		print(s1.size(), s2.size());
		puts("E");
	}
}