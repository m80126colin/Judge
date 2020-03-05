#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool map[110][110];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

inline void print(int i, int j)
{
	if (map[i][j])
	{
		putchar('*');
		return;
	}
	int k, s = 0;
	for (k = 0; k < 8; k++) s += map[i+dx[k]][j+dy[k]];
	printf("%d", s);
	return;
}

int main()
{
	bool ox;
	string s;
	int n, m, i, j, ctr;
	ox = 0;
	for (ctr = 1; cin >> n >> m, (n || m); ctr++)
	{
		memset(map, false, sizeof(map));
		for (i = 1; i <= n; i++)
		{
			cin >> s;
			for (j = 0; j < m; j++)
			{
				if (s[j] == '*') map[i][j+1] = true;
			}
		}
		if (ox) puts("");
		printf("Field #%d:\n", ctr);
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				print(i, j);
			}
			puts("");
		}
		ox = 1;
	}
}