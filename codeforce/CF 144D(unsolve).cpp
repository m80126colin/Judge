#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
#define N 1010
using namespace std;

int n, m, s, L;
int vd[N], vpi[N], edge[N][N];
int inqueue[N];

inline void SPFA()
{
	int p, i;
	queue <int> Q;
	memset(inqueue, 0, sizeof(inqueue));
	Q.push(s);
	inqueue[s] = 1;
	while (!Q.empty())
	{
		p = Q.front();
		Q.pop();
		inqueue[p] = 0;
		for (i = 1; i <= n; i++)
		{
			if (edge[p][i])
			{
				if (vd[p] + edge[p][i] < vd[i])
				{
					vd[i] = vd[p] + edge[p][i];
					vpi[i] = p;
					if (!inqueue[i])
					{
						Q.push(i);
						inqueue[i] = 1;
					}
				}
			}
		}
	}
	return ;
}

int main()
{
	int i, j, a, b, w;
	while (scanf("%d%d%d", &n, &m, &s) != EOF)
	{
		memset(edge, 0, sizeof(edge));
		for (i = 0; i < m; i++)
		{
			scanf("%d%d%d", &a, &b, &w);
			edge[a][b] = edge[b][a] = w;
		}
		memset(vpi, 0, sizeof(vpi));
		for (i = 1; i <= n; i++) vd[i] = 100000000;
		vd[s] = 0;
		SPFA();
		int ans = 0;
		scanf("%d", &L);
		for (i = 1; i <= n; i++)
			if (vd[i] == L) ans++;
		for (i = 1; i <= n; i++)
			for (j = i; j <= n; j++)
			{
				if ((vd[j] < L && vd[j] + edge[j][i] > L) || (vd[i] < L && vd[i] + edge[i][j] > L))
				{
					int tmp = (vd[i] + vd[j] + edge[i][j]) / 2;
					if (vd[j] < L && vd[j] + edge[j][i] > L && L <= tmp) ans++;
					if (vd[i] < L && vd[i] + edge[i][j] > L && L <= tmp) ans++;
					if ((vd[j] < L && vd[j] + edge[j][i] > L) && (vd[i] < L && vd[i] + edge[i][j] > L) && L == tmp) ans--;
				}
			}
		printf("%d\n", ans);
	}
}