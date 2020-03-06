/**
 *  @judge ZeroJudge
 *  @id d449
 *  @tag Disjoint Set
 */
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#define M 1010010
using namespace std;

int n, m;
int g[M], num[M], ttl;

inline int find(int x)
{
	return (x == g[x])? x: (g[x] = find(g[x]));
}

inline void uniset(int x, int y, int c)
{
	int a = find(x), b = find(y);
	if (a != b)
	{
		g[a] = g[b] = c;
		num[c] = num[a] + num[b];
		ttl--;
	}
	return;
}

inline void indep(int x, int c)
{
	int a = find(x);
	if (num[a] > 1)
	{
		g[x] = c;
		num[c] = 1;
		num[a]--;
		ttl++;
	}
	return;
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
	int a, b, c, i;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		for (i = 1; i <= n; i++) g[i] = i, num[i] = 1;
		for (i = 1; i <= m; i++) g[i + n] = i + n;
		ttl = n;
		for (i = 1; i <= m; i++)
		{
			getd(a), getd(b);
			if (a == 1) getd(c), uniset(b, c, i + n);
			else indep(b, i + n);
		}
		printf("%d\n", ttl);
	}
}