/**
 *  @judge TIOJ
 *  @id 1290
 *  @tag Shortest path, SPSP
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <vector>
#define N 1010
#define INF 2100000000
using namespace std;

struct edge{
	int b, w;
	edge() {}
	edge (int b, int w): b(b), w(w) {}
};
int n, m;
int st, ed, d[N];
vector <edge> E[N];

inline int SPFA(int s, int t)
{
	int i, j;
	for (i = 1; i <= n; i++) d[i] = INF;
	queue <int> Q;
	int inq[N];
	memset(inq, 0, sizeof(inq));
	d[s] = 0;
	Q.push(s);
	inq[s] = 1;
	while (!Q.empty())
	{
		j = Q.front();
		Q.pop();
		inq[j] = 0;
		for (i = 0; i < E[j].size(); i++)
		{
			if (d[j] + E[j][i].w < d[E[j][i].b])
			{
				d[E[j][i].b] = d[j] + E[j][i].w;
				if (!inq[E[j][i].b]) Q.push(E[j][i].b), inq[E[j][i].b] = 1;
			}
		}
	}
	if (d[t] == INF) return -1;
	return d[t];
}

inline void getd(int &d)
{
	char ch;
	while (!isdigit(ch = getchar()));
	d = 0;
	do {
		d *= 10; d += ch - '0';
	} while (isdigit(ch = getchar()));
	return ;
}

int main()
{
	int ans;
	int i, a, b, c;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		getd(st), getd(ed);
		for (i = 1; i <= n; i++) E[i].clear();
		for (i = 0; i < m; i++)
		{
			getd(a), getd(b), getd(c);
			E[a].push_back(edge(b, c));
			E[b].push_back(edge(a, c));
		}
		if ((ans = SPFA(st, ed)) < 0) puts("He is very hot");
		else printf("%d\n", ans);
	}
}