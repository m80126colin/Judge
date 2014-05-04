#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#define N 110
using namespace std;

string mine[N], touch[N];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

inline int count(int i, int j)
{
	int k, cnt = 0;
	for (k = 0; k < 8; k++)
		if (mine[i+dx[k]][j+dy[k]] == '*') cnt++;
	return cnt;
}

int main()
{
	int t, n, i, j;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d", &n);
		for (i = 1; i <= n; i++) cin >> mine[i];
		for (i = 1; i <= n; i++) cin >> touch[i];
		mine[0] = mine[n + 1] = touch[0] = touch[n + 1] = "";
		for (i = 0; i <= n + 1; i++)
		{
			mine[0] += '.', touch[0] += '.';
			mine[n + 1] += '.', touch[n + 1] += '.';
		}
		for (i = 1; i <= n; i++)
		{
			mine[i] = "." + mine[i] + ".";
			touch[i] = "." + touch[i] + ".";
		}
		int flag = 0;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (touch[i][j] == 'x' && mine[i][j] == '*')
				{
					flag = 1;
					break;
				}
		if (flag)
			for (i = 1; i <= n; i++)
				for (j = 1; j <= n; j++)
					if (mine[i][j] == '*')
						touch[i][j] = '*';
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (touch[i][j] == 'x')
					touch[i][j] = '0' + count(i, j);
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++) putchar(touch[i][j]);
			puts("");
		}
		if (t > 1) puts("");
	}
}