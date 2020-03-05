#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 1010
#define INT_MAX 2147483647
using namespace std;

struct vertex{
	int num, w;
	vertex() {}
	vertex(int _num, int _w): num(_num), w(_w) {}
}V[MAX];
bool visited[MAX];
int E[MAX][MAX];
int n, m, dp[MAX];
struct comp{
	bool operator() (vertex left, vertex right)
	{
		return left.w > right.w;
	}
};

inline int getd(int &d)
{
	char ch;
	while (!isdigit(ch = getchar()));
	d = 0;
	do
	{
		d = d * 10 + ch - '0';
	} while (isdigit(ch = getchar()));
	return 1;
}

void dijkstra(int s)
{
	int i, j;
	priority_queue<vertex, vector <vertex>, comp> q;
	for (i = 1; i <= n; i++) V[i].num = i, V[i].w = INT_MAX;
	memset(visited, 0, sizeof(visited));
	V[s].w = 0;
	q.push(V[s]);
	while (!q.empty())
	{
		vertex tmp = q.top();
		q.pop();
		if (!visited[tmp.num])
		{
			V[tmp.num] = tmp;
			visited[tmp.num] = 1;
			for (j = 1; j <= n; j++)
			{
				if (!visited[j] && E[tmp.num][j]) q.push(vertex(j, tmp.w+E[tmp.num][j]));
			}
		}
	}
}
bool cmp(vertex a, vertex b)
{
	return a.w > b.w;
}
inline int DP(int a)
{
	int i, j;
	memset(dp, 0, sizeof(dp));
	dp[a] = 1;
	for (i = a; i <= n; i++)
	{
		for (j = a; j < i; j++)
		{
			if (E[V[i].num][V[j].num] && V[i].w < V[j].w) dp[i] += dp[j];
		}
	}
	return dp[n];
}
int main()
{
	//freopen("q10917.txt","r",stdin);
	//freopen("q10917.out","w",stdout);
	int i;
	while (getd(n), n)
	{
		getd(m);
		memset(E, 0, sizeof(E));
		for (i = 1; i <= m; i++)
		{
			int a, b, d;
			getd(a), getd(b), getd(d);
			E[a][b] = E[b][a] = d;
		}
		dijkstra(2);
		sort(V+1, V+n+1, cmp);
		for (i = 1; i <= n, V[i].num != 1; i++);
		printf("%d\n", DP(i));
	}
}