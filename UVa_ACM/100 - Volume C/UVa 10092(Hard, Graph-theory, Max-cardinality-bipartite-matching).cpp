/*
Maximum cardinality bipartite matching
二分圖最大匹配 O(V^3)
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX 1010
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

int nk, np, c[MAX];

void build(int left, int right, int j)
{
	int i;
	for (i = left; i < right; i++)
		r[i][j] = true;
	return ;
}

int main()
{
	int i, j, k, tmp, ans;
	while (scanf("%d%d", &nk, &np), (nk || np))
	{
		m = n = 0;
		memset(r, 0, sizeof(r));
		c[0] = 0;
		for (i = 1; i <= nk; i++)
		{
			scanf("%d", &c[i]);
			c[i] += c[i - 1];
		}
		for (j = 0; j < np; j++)
		{
			for (scanf("%d", &k); k; k--)
			{
				scanf("%d", &tmp);
				build(c[tmp - 1], c[tmp], j);
			}
		}
		n = c[nk];
		m = np;
		ans = match();
		int flag;
		if (ans == c[nk])
		{
			puts("1");
			j = 1;
			for (i = 0; i < c[nk]; i++)
			{
				if (i >= c[j])
				{
					puts("");
					flag = 0;
					j++;
				}
				if (flag) putchar(' ');
				printf("%d", N[i] + 1);
				flag = 1;
			}
			puts("");
		}
		else puts("0");
	}
}