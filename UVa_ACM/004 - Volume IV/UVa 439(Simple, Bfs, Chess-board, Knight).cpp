#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
#define N 8
using namespace std;

int board[N][N], visited[N][N];

inline int bfs(char *s, char *t)
{
	int sx, sy, tx, ty;
	int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
	int dy[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
	memset(board, 0, sizeof(board));
	memset(visited, 0, sizeof(visited));
	sx = s[0] - 'a', sy = s[1] - '1';
	tx = t[0] - 'a', ty = t[1] - '1';
	queue <int> Q;
	Q.push(sx * N + sy);
	visited[sx][sy] = 1;
	while (!Q.empty())
	{
		if (visited[tx][ty]) return board[tx][ty];
		int p = Q.front(), px, py;
		px = p / N, py = p % N;
		Q.pop();
		for (int i = 0; i < 8; i++)
		{
			if (px + dx[i] >= 0 && px + dx[i] < N && py + dy[i] >= 0 && py + dy[i] < N && !visited[px + dx[i]][py + dy[i]])
			{
				board[px + dx[i]][py + dy[i]] = board[px][py] + 1;
				Q.push((px + dx[i]) * N + (py + dy[i]));
				visited[px + dx[i]][py + dy[i]] = 1;
			}
		}
	}
	return board[tx][ty];
}

int main()
{
	char s[3], t[3];
	while (scanf("%s%s", s, t) != EOF)
		printf("To get from %s to %s takes %d knight moves.\n", s, t, bfs(s, t));
}