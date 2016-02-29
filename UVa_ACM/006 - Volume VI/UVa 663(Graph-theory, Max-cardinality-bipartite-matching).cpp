#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX 110
int n, m;
int N[MAX], M[MAX], tmp[MAX];
bool r[MAX][MAX], visited[MAX];

int DFS(int i)
{
	int j;
	for (j = 0; j < n; j++)
	{
		if (!visited[j] && r[i][j])
		{
			visited[j] = 1;
			if (M[j] == -1 || DFS(M[j]))
			{
				N[i] = j;
				M[j] = i;
				return 1;
			}
		}
	}
	return 0;
}

int match()
{
	int i, sum = 0;
	memset(N, -1, sizeof(N));
	memset(M, -1, sizeof(M));
	for (i = 0; i < n; i++)
	{
		memset(visited, 0, sizeof(visited));
		if (DFS(i)) sum++;
	}
	return sum;
}

struct rect
{
	int x1, x2, y1 , y2;
}R[MAX];
struct point
{
	int x, y;
}P[MAX];

inline bool Inner(int i, int j)
{
	return (P[i].x > R[j].x1 && P[i].x < R[j].x2 && P[i].y > R[j].y1 && P[i].y < R[j].y2);
}

int main()
{
	int i, j, t, ans, flag;
	for (t = 1; scanf("%d", &n), n; t++)
	{
		for (i = 0; i < n; i++)
			scanf("%d%d%d%d", &R[i].x1, &R[i].x2, &R[i].y1, &R[i].y2);
		for (i = 0; i < n; i++)
			scanf("%d%d", &P[i].x, &P[i].y);
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				r[i][j] = Inner(i, j);
		printf("Heap %d\n", t);
		m = n;
		ans = match();
		flag = 0;
		if (ans == n)
		{
			for (j = 0; j < n; j++)
				tmp[j] = M[j];
			for (j = 0; j < n; j++)
			{
				i = tmp[j];
				r[i][j] = 0;
				if (match() == ans) continue ;
				else
				{
					if (flag) putchar(' ');
					printf("(%c,%d)", 'A' + j, tmp[j] + 1);
					flag = 1;
				}
				r[i][j] = 1;
			}
		}
		if (!flag) printf("none");
		puts("\n");
	}
}