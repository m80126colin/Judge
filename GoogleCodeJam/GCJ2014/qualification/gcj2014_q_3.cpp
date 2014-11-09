#include <cstdio>
#include <iostream>
using namespace std;

//#define debug
#define test
#define dN 5
#define dM 2
#define dK 8
#define N 50
#define sqN ((N) * (N))
int state[N + 1][N + 1][sqN];
int result[N + 1][N + 1][sqN][N][N];
int board[N][N], tmp[N][N];
int n, m, k, s;
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

int count(int x, int y)
{
	int z, x1, y1, res = 0;
	for (z = 0; z < 8; z++)
	{
		x1 = x + dx[z];
		y1 = y + dy[z];
		if (x1 < 0 || y1 < 0 || x1 >= n || y1 >= m || board[x1][y1] == 0)
			res += 0;
		else res += 1;
	}
	return res;
}

int floodfill(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= m)
		return 0;
	if (tmp[x][y] == 1 || board[x][y] == 1)
		return 0;
	tmp[x][y] = 1;
	if (count(x, y) > 0)
		return 1;
	int z, res = 1;
	for (z = 0; z < 8; z++)
		res += floodfill(x + dx[z], y + dy[z]);
	return res;
}

int re(int x, int y)
{
	int i, j;
	if (x == 0)
	{
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
			{
#ifdef debug
				/*memset(tmp, 0, sizeof(tmp));
				if (n == 7 && m == 4 && k == 3)
					printf("i=%d, j=%d, floodfill=%d\n", i, j, floodfill(i, j));*/
#endif
				memset(tmp, 0, sizeof(tmp));
				if (floodfill(i, j) == s - k)
				{
					int x1, y1;
					for (x1 = 0; x1 < n; x1++)
					{
						for (y1 = 0; y1 < m; y1++)
						{
							if (x1 == i && y1 == j) result[n][m][k][x1][y1] = -1;
							else if (board[x1][y1] == 1) result[n][m][k][x1][y1] = 1;
							else result[n][m][k][x1][y1] = 0;
#ifdef debug
							if (x1 == i && y1 == j) putchar('c');
							else if (board[x1][y1] == 1) putchar('*');
							else putchar('.');
#endif
						}
#ifdef debug
						puts("");
#endif
					}
					return 1;
				}
			}
		return 0;
	}
	for (; y < s; y++)
	{
		i = y / m;
		j = y % m;
		board[i][j] = 1;
#ifdef debug
		/*if (n == 7 && m == 4 && k == 3)
			printf("bomb=(%d, %d)\n", i, j);*/
#endif
		if (re(x - 1, y + 1))
			return 1;
		board[i][j] = 0;
	}
	return 0;
}

void check()
{
	int i, j;
	s = n * m;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			board[i][j] = 0;
	state[n][m][k] = re(k, 0);
#ifdef debug
	printf("n=%d, m=%d, k=%d, state=%d\n", n, m, k, state[n][m][k]);
#endif
}

int main()
{
	int i, j;
	for (n = 1; n <= N; n++)
		for (m = 1; m <= n; m++)
			for (k = 0; k < n * m; k++)
			{
				check();
#ifdef debug
				if (n == dN && m == dM && k == dK)
					system("PAUSE");
#endif
			}
#ifndef debug
#ifdef test
	system("PAUSE");
	freopen("C-large.in", "r+", stdin);
	freopen("C-large.out", "w+", stdout);
#endif
#endif
	int t, cnt, flag;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		flag = 0;
		scanf("%d%d%d", &n, &m, &k);
		printf("Case #%d:\n", cnt);
		if (m > n)
		{
			swap(n, m);
			flag = 1;
		}
		if (state[n][m][k] == 0)
			puts("Impossible");
		else
		{
			if (flag)
			{
				swap(n, m);
				for (i = 0; i < n; i++)
				{
					for (j = 0; j < m; j++)
						if (result[m][n][k][j][i] == -1) putchar('c');
						else if (result[m][n][k][j][i] == 0) putchar('.');
						else putchar('*');
					puts("");
				}
			}
			else
			{
				for (i = 0; i < n; i++)
				{
					for (j = 0; j < m; j++)
						if (result[n][m][k][i][j] == -1) putchar('c');
						else if (result[n][m][k][i][j] == 0) putchar('.');
						else putchar('*');
					puts("");
				}
			}
		}
	}
}