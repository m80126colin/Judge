#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <vector>
#define N 1010
using namespace std;

int maze[N][N], weight[N][N], n, m;
bool visited[N][N];
struct point
{
	int x, y;
	point() { x = y = 0; }
	point(int x, int y): x(x), y(y) {}
};
struct cmp
{
	bool operator() (point a, point b)
	{
		return weight[a.x][a.y] > weight[b.x][b.y];
	}
};
point d[4] = {point(1, 0), point(0, 1), point(-1, 0), point(0, -1)};

inline int shortest_path()
{
	int i, j;
	priority_queue <point, vector <point>, cmp> PQ;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			weight[i][j] = 10000000;
	memset(visited, 0, sizeof(visited));
	PQ.push(point(0, 0));
	weight[0][0] = maze[0][0];
	while (!PQ.empty())
	{
		point q = PQ.top();
		visited[q.x][q.y] = 1;
		PQ.pop();
		for (i = 0; i < 4; i++)
		{
			if (q.x + d[i].x >= 0 && q.x + d[i].x < n && q.y + d[i].y >= 0 && q.y + d[i].y < m)
			{
				if (weight[q.x + d[i].x][q.y + d[i].y] > weight[q.x][q.y] + maze[q.x + d[i].x][q.y + d[i].y])
				{
					weight[q.x + d[i].x][q.y + d[i].y] = weight[q.x][q.y] + maze[q.x + d[i].x][q.y + d[i].y];
					PQ.push(point(q.x + d[i].x, q.y + d[i].y));
				}
			}
			if (visited[n - 1][m - 1]) return weight[n - 1][m - 1];
		}
	}
	return weight[n - 1][m - 1];
}

int main()
{
	int t, i, j;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d%d", &n, &m);
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				scanf("%d", &maze[i][j]);
		printf("%d\n", shortest_path());
	}
}