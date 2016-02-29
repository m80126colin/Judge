/*
Maximum cardinality bipartite matching
�G���ϳ̤j�ǰt O(V^3)
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;

#define MAX 110
int n, m; /* n, m ���ⶰ�X���I�� */
int N[MAX], M[MAX]; /* N, M �O�����ۤǰt���I�s�� */
bool r[MAX][MAX], visited[MAX]; /* R �ؤG���ϡBvisited �O���C�����L���X */

int DFS(int i)
{
	int j;
	for (j = 0; j < m; j++)
	{
		if (!visited[j] && r[i][j]) /* ���� */
		{
			visited[j] = 1;
			if (M[j] == -1 || DFS(M[j])) /* �ˬd�O�_���ǰt�άO�i���ǰt */
			{
				N[i] = j;
				M[j] = i;
				return 1; /* �W�[�ǰt�� */
			}
		}
	}
	return 0;
}

int match()
{
	int i, sum = 0;
	memset(N, -1, sizeof(N));
	memset(M, -1, sizeof(M)); /* �k�s */
	for (i = 0; i < n; i++)
	{
		memset(visited, 0, sizeof(visited));
		if (DFS(i)) sum++;
	}
	return sum;
}

struct point
{
	int x, y;
}path[MAX], play[MAX];
int flag;

double dis(point a, point b)
{
	return sqrt(1.0 * (a.x - b.x) * (a.x - b.x) + 1.0 * (a.y - b.y) * (a.y - b.y));
}

bool can(int i, int j)
{
	return (2.0 * dis(path[i], path[i + 1]) > dis(path[i], play[j]) + dis(play[j], path[i + 1]));
}

void print(int i, int j)
{
	if (flag) putchar(' ');
	if (i >= 0)
		printf("%d %d", path[i].x, path[i].y);
	if (j >= 0)
		printf("%d %d", play[j].x, play[j].y);
	flag = 1;
	return ;
}

int main()
{
	int t, i, j, ans;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d%d", &n, &m);
		for (i = 0; i < n; i++)
			scanf("%d%d", &path[i].x, &path[i].y);
		for (j = 0; j < m; j++)
			scanf("%d%d", &play[j].x, &play[j].y);
		ans = n;
		n--;
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				r[i][j] = can(i, j);
		match();
		for (i = 0; i < n; i++)
			if (N[i] != -1) ans++;
		printf("%d\n", ans);
		flag = 0;
		for (i = 0; i < n; i++)
		{
			print(i, -1);
			if (N[i] != -1) print(-1, N[i]);
		}
		print(n, -1);
		puts("");
		if (t > 1) puts("");
	}
}