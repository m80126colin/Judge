/**
 *  @judge ZeroJudge
 *  @id d831
 *  @tag Disjoint set, Union find set
 */
#include <stdio.h>
#include <ctype.h>
#include <iostream>
#define N 1000010
using namespace std;

int n, m;
int num[N], g[N], maxn;

inline int find(int x)
{
	return (x == g[x])? x: (g[x] = find(g[x]));
}

inline void uniset(int a, int b)
{
	int ta = find(a), tb = find(b);
	if (ta != tb)
	{
		g[tb] = ta;
		num[ta] += num[tb];
		num[tb] = 0;
		if (num[ta] > maxn) maxn = num[ta];
	}
	return ;
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
	int i, ta, tb;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		for (i = 0; i < n; i++) num[i] = 1, g[i] = i;
		maxn = 1;
		for (i = 0; i < m; i++)
		{
			getd(ta), getd(tb);
			uniset(ta, tb);
		}
		printf("%d\n", maxn);
	}
}