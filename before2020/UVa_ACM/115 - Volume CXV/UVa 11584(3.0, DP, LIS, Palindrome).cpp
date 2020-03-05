#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 1010
#define IMAX 100000000
int t, dp[MAX], p[MAX][MAX], len;
char s[MAX];

int main()
{
	int i, j, left, right;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%s", s);
		len = strlen(s);
		for (i = 0; i <= len; i++) p[i][i] = 1; // even
		for (i = 0; i < len; i++) p[i][i + 1] = 1; // odd
		for (j = 2; j <= len; j++)
		{
			for (i = j / 2; i < len; i++)
			{
				left = i - j / 2;
				right = i + (j - j / 2);
				if (left >= 0 && right <= len)
				{
					if (s[left] == s[right - 1]) p[left][right] = p[left + 1][right - 1];
					else p[left][right] = 0;
				}
			}
		}
		for (i = 0; i <= len; i++) dp[i] = i;
		for (i = 0; i <= len; i++)
			for (j = 0; j < i; j++)
				if (p[j][i]) dp[i] = min(dp[i], dp[j] + 1);
		printf("%d\n", dp[len]);
	}
}