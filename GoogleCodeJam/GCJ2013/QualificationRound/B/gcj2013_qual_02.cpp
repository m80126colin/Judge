#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 110
int t, n, m;
int a[MAX][MAX], mat[MAX][MAX], c[MAX];
int li[MAX], len;

int chk(int i, int j, int id, int inc)
{
	if (id == -1)
	{
		for (; i >= 0 && i < n; i += inc)
			if (a[i][j] != a[0][j])
				return 0;
	}
	else
	{
		for (; j >= 0 && j < m; j += inc)
			if (a[i][j] != a[i][0])
				return 0;
	}
	return 1;
}

int sol()
{
	int i, j, k;
	memset(c, 0, sizeof(c));
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			c[a[i][j]] = 1;
	c[100] = 1;
	len = 0;
	for (i = 0; i < MAX; i++)
		if (c[i]) li[len++] = i;
	for (k = 0; k < len - 1; k++)
	{
		memset(mat, 0, sizeof(mat));
		for (i = 0; i < n; i++)
			if (a[i][0] == li[k] && a[i][m - 1] == li[k])
				if (chk(i, 0, 1, 1))
					for (j = 0; j < m; j++)
						mat[i][j] = 1;
		for (j = 0; j < m; j++)
			if (a[0][j] == li[k] && a[n - 1][j] == li[k])
				if (chk(0, j, -1, 1))
					for (i = 0; i < n; i++)
						mat[i][j] = 1;
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				if (a[i][j] == li[k])
				{
					if (mat[i][j]) a[i][j] = li[k + 1];
					else return 0;
				}
	}
	return 1;
}

int main()
{
	freopen("B-large.in", "r+", stdin);
	freopen("B-large.out", "w+", stdout);
	int cnt, i, j;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		scanf("%d%d", &n, &m);
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				scanf("%d", &a[i][j]);
		printf("Case #%d: ", cnt);
		if (sol()) puts("YES");
		else puts("NO");
	}
}