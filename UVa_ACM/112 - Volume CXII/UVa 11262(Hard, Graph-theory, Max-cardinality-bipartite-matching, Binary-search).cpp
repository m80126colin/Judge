/*
Maximum cardinality bipartite matching
二分圖最大匹配 O(V^3)
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;

#define MAX 110
int n, m; /* n, m 為兩集合的點數 */
int N[MAX], M[MAX]; /* N, M 記錄互相匹配的點編號 */
bool visited[MAX]; /* R 建二分圖、visited 記錄每次有無走訪 */
double r[MAX][MAX];

int DFS(int i, int lim)
{
	int j;
	for (j = 0; j < m; j++)
	{
		if (!visited[j] && r[i][j] <= (double) lim) /* 有邊 */
		{
			visited[j] = 1;
			if (M[j] == -1 || DFS(M[j], lim)) /* 檢查是否未匹配或是可換匹配 */
			{
				N[i] = j;
				M[j] = i;
				return 1; /* 增加匹配數 */
			}
		}
	}
	return 0;
}

int match(int lim)
{
	int i, sum = 0;
	memset(N, -1, sizeof(N));
	memset(M, -1, sizeof(M)); /* 歸零 */
	for (i = 0; i < n; i++)
	{
		memset(visited, 0, sizeof(visited));
		if (DFS(i, lim)) sum++;
	}
	return sum;
}

struct point
{
	int x, y;
}a[MAX], b[MAX], pt;
char tmp[MAX];
int k, ans;

double dis(point X, point Y)
{
	return sqrt(1.0 * (X.x - Y.x) * (X.x - Y.x) + 1.0 * (X.y - Y.y) * (X.y - Y.y));
}

int sol()
{
	int left, right, middle;
	left = 0;
	right = 10000;
	if (match(right) < k) return 0;
	while (left < right)
	{
		middle = (left + right) / 2;
		if (match(middle) < k) left = middle + 1;
		else right = middle;
	}
	ans = right;
	return 1;
}

int main()
{
	int t, i, j, s;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d%d", &s, &k);
		n = m = 0;
		for (i = 0; i < s; i++)
		{
			scanf("%d%d%s", &pt.x, &pt.y, tmp);
			if (strcmp(tmp, "blue") == 0) a[n++] = pt;
			else b[m++] = pt;
		}
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				r[i][j] = dis(a[i], b[j]);
		if (sol()) printf("%d\n", ans);
		else puts("Impossible");
	}
}