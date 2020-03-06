/**
 *  @judge UVa
 *  @id 11159
 *  @tag Graph theory, Max cardinality bipartite matching
 */
/*
Maximum cardinality bipartite matching
�G���ϳ̤j�ǰt O(V^3)
*/
#include <stdio.h>
#include <string.h>
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