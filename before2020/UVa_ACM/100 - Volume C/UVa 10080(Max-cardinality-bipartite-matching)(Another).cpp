/**
 *  @judge UVa
 *  @id 10080
 *  @tag Max cardinality bipartite matching
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX 110
#define DIS2(x, y) ((x) * (x) + (y) * (y))
struct point
{
	double x, y;
}hog[MAX], hole[MAX];
int n, m;
int N[MAX], M[MAX];
bool r[MAX][MAX], visited[MAX];

int DFS(int i)
{
	int j;
	for (j = 0; j < m; j++)
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

int main()
{
	int i, j;
	double s, v, dis;
	while (scanf("%d%d%lf%lf", &n, &m, &s, &v) != EOF)
	{
		for (i = 0; i < n; i++)
			scanf("%lf%lf", &hog[i].x, &hog[i].y);
		for (j = 0; j < m; j++)
			scanf("%lf%lf", &hole[j].x, &hole[j].y);
		dis = (s * v) * (s * v);
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				r[i][j] = (DIS2(hog[i].x - hole[j].x, hog[i].y - hole[j].y) <= dis);
		printf("%d\n", n - match());
	}
}