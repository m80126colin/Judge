/**
 *  @judge UVa
 *  @id 260
 *  @tag 2.0, 2D map, DFS
 */
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 210
int n;
int dx[6] = {-1, -1, 0, 0, 1, 1}, dy[6] = {-1, 0, -1, 1, 0, 1};
int visited[MAX][MAX];
char M[MAX][MAX];

int input()
{
	int i;
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
		gets(M[i]);
	return n;
}

int DFS(int x, int y)
{
	int i;
	visited[x][y] = 1;
	if (y + 1 == n) return 1;
	for (i = 0; i < 6; i++)
	{
		if (0 <= x + dx[i] && x + dx[i] < n && 0 <= y + dy[i] && y + dy[i] < n)
			if (M[x + dx[i]][y + dy[i]] == 'w' && !visited[x + dx[i]][y + dy[i]] && DFS(x + dx[i], y + dy[i]))
				return 1;
	}
	return 0;
}

int sol()
{
	int i;
	memset(visited, 0, sizeof(visited));
	for (i = 0; i < n; i++)
		if (M[i][0] == 'w' && !visited[i][0] && DFS(i, 0))
			return 1;
	return 0;
}

int main()
{
	int cnt;
	for (cnt = 1; input(); cnt++)
		printf("%d %s\n", cnt, sol()? "W": "B");
}