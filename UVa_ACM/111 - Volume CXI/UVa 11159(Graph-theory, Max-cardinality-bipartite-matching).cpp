/*
Maximum cardinality bipartite matching
二分圖最大匹配 O(V^3)
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX 110
int n, m; /* n, m 為兩集合的點數 */
int N[MAX], M[MAX]; /* N, M 記錄互相匹配的點編號 */
bool r[MAX][MAX], visited[MAX]; /* R 建二分圖、visited 記錄每次有無走訪 */

int DFS(int i)
{
	int j;
	for (j = 0; j < m; j++)
	{
		if (!visited[j] && r[i][j]) /* 有邊 */
		{
			visited[j] = 1;
			if (M[j] == -1 || DFS(M[j])) /* 檢查是否未匹配或是可換匹配 */
			{
				N[i] = j;
				M[j] = i;
				return 1; /* 增加匹配數 */
			}
		}
	}
	return 0;
}

int match()
{
	int i, sum = 0;
	memset(N, -1, sizeof(N));
	memset(M, -1, sizeof(M)); /* 歸零 */
	for (i = 0; i < n; i++)
	{
		memset(visited, 0, sizeof(visited));
		if (DFS(i)) sum++;
	}
	return sum;
}

int a[MAX], b[MAX];

int main()
{
	int i, j, t, cnt, ans;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		scanf("%d", &m);
		for (j = 0; j < m; j++)
			scanf("%d", &b[j]);
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				r[i][j] = ((a[i] && b[j] % a[i] == 0) || (a[i] == 0 && b[j] == 0));
		ans = match();
		printf("Case %d: %d\n", cnt, ans);
	}
}