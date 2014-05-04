#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 10010
int n, m, l, ans;
vector<int> edge[MAX];
int node[MAX];

int main()
{
	int t, i, j;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d%d%d", &n, &m, &l);
		memset(node, 0, sizeof(node));
		for (i = 1; i <= n; i++)
			edge[i].clear();
		for (i = 0; i < m; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			edge[a].push_back(b);
		}
		ans = 0;
		for (i = 0; i < l; i++)
		{
			int a;
			scanf("%d", &a);
			vector<int> Q;
			Q.clear();
			if (!node[a])
			{
				Q.push_back(a);
				node[a] = 1;
				ans++;
			}
			while (!Q.empty())
			{
				int b = Q.front();
				Q.erase(Q.begin());
				for (j = 0; j < edge[b].size(); j++)
				{
					if (!node[edge[b][j]])
					{
						Q.push_back(edge[b][j]);
						node[edge[b][j]] = 1;
						ans++;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
}