#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int n, m, x, y, move;
int known[15][15], visited[15][15];
char map[15][15];

void Input()
{
	int i, j;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			cin >> map[i][j];
	return ;
}

int OneMove()
{
	int i;
	int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
	visited[x][y] = 1;
	for (i = 0; i < 4; i++)
		if (x + dx[i] > 0 && x + dx[i] <= n && y + dy[i] > 0 && y + dy[i] <= m)
			known[x + dx[i]][y + dy[i]] = 1;
	for (i = 0; i < 4; i++)
		if (x + dx[i] > 0 && x + dx[i] <= n && y + dy[i] > 0 && y + dy[i] <= m && map[x + dx[i]][y + dy[i]] == '0' && !visited[x + dx[i]][y + dy[i]])
		{
			x += dx[i];
			y += dy[i];
			break;
		}
	if (i == 4)
		return 0;
	return 1;
}

void PrintLine()
{
	int j;
	putchar('|');
	for (j = 1; j <= m; j++)
		printf("---|");
	puts("");
	return ;
}

void Print()
{
	int i, j;
	puts("");
	PrintLine();
	for (i = 1; i <= n; i++)
	{
		putchar('|');
		for (j = 1; j <= m; j++)
			printf(" %c |", (known[i][j])?map[i][j]:'?');
		puts("");
		PrintLine();
	}
	puts("");
	printf("NUMBER OF MOVEMENTS: %d\n", move);
}

int main()
{
	while (cin >> n >> m, (n || m))
	{
		scanf("%d%d", &x, &y);
		Input();
		memset(known, 0, sizeof(known));
		memset(visited, 0, sizeof(visited));
		known[x][y] = 1;
		for (move = 0; OneMove(); move++) ;
		Print();
	}
}