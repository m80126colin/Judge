/**
 *  @judge UVa
 *  @id 11138
 *  @tag Graph theory, Max cardinality bipartite matching, Read code
 */
#include <stdio.h>
#include <string.h>

#define MAX 510
int n, m;
int N[MAX], M[MAX];
int r[MAX][MAX];

void input()
{
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &r[i][j]);
	return ;
}

int visited[MAX];
int ans;

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
	int i;
	ans = 0;
	memset(N, -1, sizeof(N));
	memset(M, -1, sizeof(M));
	for (i = 0; i < n; i++)
	{
		memset(visited, 0, sizeof(visited));
		if (DFS(i)) ans++;
	}
	return ans;
}

int main()
{
	int t, cnt;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		input();
		match();
		printf("Case %d: ", cnt);
		printf("a maximum of %d nuts and bolts ", ans);
		printf("can be fitted together\n");
	}
	return 0;
}