/**
 *  @judge UVa
 *  @id 531
 *  @tag 3.0, DP, LCS
 */
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#define MAX 110
struct paragraph
{
	int size;
	string s[MAX];
	friend istream& operator >> (istream& is, paragraph& p)
	{
		for (p.size = 0; is >> p.s[p.size]; p.size++)
			if (p.s[p.size] == "#") return is;
		return is;
	}
}s1, s2;
int dp[MAX][MAX], path[MAX][MAX], cnt;

void LCS()
{
	int i, j;
	for (i = 0; i < s1.size; i++)
		dp[i][0] = path[i][0] = 0;
	for (j = 0; j < s2.size; j++)
		dp[0][j] = path[0][j] = 0;
	for (i = 1; i <= s1.size; i++)
		for (j = 1; j <= s2.size; j++)
		{
			if (s1.s[i - 1] == s2.s[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				path[i][j] = 1;
			}
			else
			{
				if (dp[i][j - 1] > dp[i - 1][j])
				{
					dp[i][j] = dp[i][j - 1];
					path[i][j] = 2;
				}
				else
				{
					dp[i][j] = dp[i - 1][j];
					path[i][j] = 3;
				}
			}
		}
	return ;
}

void print(int x, int y)
{
	if (x == 0 || y == 0)
		return ;
	if (path[x][y] == 1)
	{
		print(x - 1, y - 1);
		if (cnt) putchar(' ');
		printf("%s", s1.s[x - 1].c_str());
		cnt++;
	}
	else if (path[x][y] == 2)
		print(x, y - 1);
	else
		print(x - 1, y);
	return ;
}

int main()
{
	while (cin >> s1 >> s2)
	{
		cnt = 0;
		LCS();
		print(s1.size, s2.size);
		puts("");
	}
}