/**
 *  @judge UVa
 *  @id 11262
 *  @tag Hard, Graph theory, Max cardinality bipartite matching, Binary search
 */
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
bool visited[MAX]; /* R �ؤG���ϡBvisited �O���C�����L���X */
double r[MAX][MAX];

int DFS(int i, int lim)
{
	int j;
	for (j = 0; j < m; j++)
	{
		if (!visited[j] && r[i][j] <= (double) lim) /* ���� */
		{
			visited[j] = 1;
			if (M[j] == -1 || DFS(M[j], lim)) /* �ˬd�O�_���ǰt�άO�i���ǰt */
			{
				N[i] = j;
				M[j] = i;
				return 1; /* �W�[�ǰt�� */
			}
		}
	}
	return 0;
}

int match(int lim)
{
	int i, sum = 0;
	memset(N, -1, sizeof(N));
	memset(M, -1, sizeof(M)); /* �k�s */
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