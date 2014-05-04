#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 110
int w, h, visited[MAX][MAX];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
char M[MAX][MAX];

int input()
{
	if (scanf("%d%d", &w, &h) == EOF)
		return EOF;
	getchar();
	int i;
	for (i = 0; i < h; i++)
		gets(M[i]);
	return 0;
}

int istrap(int x, int y)
{
	int i;
	for (i = 0; i < 4; i++)
		if (M[x + dx[i]][y + dy[i]] == 'T')
			return 1;
	return 0;
}

int DFS(int x, int y)
{
	int i, ans = 0;
	visited[x][y] = 1;
	if (M[x][y] == 'G') ans++;
	if (!istrap(x, y))
	{
		for (i = 0; i < 4; i++)
			if (M[x + dx[i]][y + dy[i]] != '#' && !visited[x + dx[i]][y + dy[i]])
				ans += DFS(x + dx[i], y + dy[i]);
	}
	return ans;
}

int sol()
{
	int i, j, ans = 0;
	memset(visited, 0, sizeof(visited));
	for (i = 0; i < h; i++)
		for (j = 0; j < w; j++)
			if (M[i][j] == 'P')
				ans = DFS(i, j);
	return ans;
}

int main()
{
	while (input() != EOF)
		printf("%d\n", sol());
}