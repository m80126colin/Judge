#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define N 10010
using namespace std;

struct edge
{
	int a, b, w;
	edge () {}
	edge (int a, int b, int w): a(a), b(b), w(w) {}
};
int n, m;
int g[N], ttl;
vector <edge> E;

inline int find(int x)
{
	return (x == g[x])? x: (g[x] = find(g[x]));
}

inline int uniset(int x, int y)
{
	int a = find(x), b = find(y);
	if (a != b)
	{
		g[a] = b;
		ttl--;
		return 1;
	}
	return 0;
}

inline void Init()
{
	int i;
	for (i = 1; i <= n; i++)
		g[i] = i;
	ttl = n;
	return ;
}

inline bool cmp(edge left, edge right)
{
	return left.w < right.w;
}

inline int MST()
{
	int i, ctr, ans;
	ctr = ans = 0;
	sort(E.begin(), E.end(), cmp);
	for (i = 0; i < E.size(); i++)
	{
		if (ctr == n - 1) return ans;
		if (uniset(E[i].a, E[i].b))
			ans += E[i].w, ctr++;
	}
	return ans;
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
	int i, a, b, c;
	while (scanf("%d%d", &n, &m), (n || m))
	{
		Init();
		E.clear();
		for (i = 1; i <= m; i++)
		{
			getd(a), getd(b), getd(c);
			E.push_back(edge(a, b, c));
			uniset(a, b);
		}
		if (ttl == 1) Init(), printf("%d\n", MST());
		else puts("-1");
	}
}