#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
#define N 110
using namespace std;

int n, r, V[N][N];

int SPFA(int a, int b)
{
	queue<int> Q;
	int inq[N], len[N];
	memset(inq, 0, sizeof(inq));
	memset(len, 0, sizeof(len));
	Q.push(a);
	inq[a] = 1;
	len[a] = 2147483647;
	while (!Q.empty())
	{
		int p = Q.front();
		Q.pop();
		inq[p] = 0;
		for (int i = 1; i <= n; i++)
		{
			int j = min(len[p], V[p][i]);
			if (V[p][i] && j > len[i])
			{
				len[i] = j;
				if (!inq[i])
				{
					Q.push(i);
					inq[i] = 1;
				}
			}
		}
	}
	return len[b];
}

int main()
{
	int i, t, a, b, tmp;
	for (t = 1; scanf("%d%d", &n, &r), (n || r); t++)
	{
		memset(V, 0, sizeof(V));
		for (i = 0; i < r; i++)
		{
			scanf("%d%d%d", &a, &b, &tmp);
			V[a][b] = V[b][a] = tmp;
		}
		scanf("%d%d%d", &a, &b, &tmp);
		i = SPFA(a, b);
		printf("Scenario #%d\nMinimum Number of Trips = %d\n\n", t, tmp / (i - 1) + (tmp % (i - 1) > 0));
	}
}