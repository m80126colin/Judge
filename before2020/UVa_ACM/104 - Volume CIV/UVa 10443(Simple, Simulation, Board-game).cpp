#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX 110
int r, c, n;
int *today[MAX], *tomorrow[MAX];
int map1[MAX][MAX], map2[MAX][MAX];

int Win(int a, int b)
{
	return (a - 1) == b || (a == 1 && b == 3);
}

void OneDay()
{
	int i, j, k;
	int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
	for (i = 1; i <= r; i++)
		for (j = 1; j <= c; j++)
		{
			tomorrow[i][j] = today[i][j];
			for (k = 0; k < 4; k++)
				if (Win(today[i + dx[k]][j + dy[k]], today[i][j]))
				{
					tomorrow[i][j] = today[i + dx[k]][j + dy[k]];
					break;
				}
		}
	for (i = 0; i < MAX; i++) swap(today[i], tomorrow[i]);
	return;
}

int main()
{
	int i, j, t;
	char ch, H[6] = "0PSR";
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d%d%d", &r, &c, &n);
		memset(map1, 0, sizeof(map1));
		memset(map2, 0, sizeof(map2));
		cin.ignore(1);
		for (i = 1; i <= r; i++)
		{
			for (j = 1; j <= c; j++)
			{
				ch = getchar();
				if (ch == 'R') map1[i][j] = 3;
				else if (ch == 'S') map1[i][j] = 2;
				else if (ch == 'P') map1[i][j] = 1;
			}
			getchar();
		}
		for (i = 0; i < MAX; i++) today[i] = map1[i];
		for (i = 0; i < MAX; i++) tomorrow[i] = map2[i];
		for (i = 0; i < n; i++)
			OneDay();
		for (i = 1; i <= r; i++)
		{
			for (j = 1; j <= c; j++)
				putchar(H[today[i][j]]);
			puts("");
		}
		if (t > 1) puts("");
	}
}