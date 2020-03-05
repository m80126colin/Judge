#include <stdio.h>
#include <ctype.h>
#include <iostream>
#define N 1000010
using namespace std;

int n;
int g[N], num[N], ttl, maxn;

inline int find(int x)
{
	return (x == g[x])? x: (g[x] = find(g[x]));
}

inline void uniset(int a, int b)
{
	int ta, tb;
	ta = find(a), tb = find(b);
	if (ta != tb)
	{
		g[tb] = ta;
		ttl--;
		num[ta] += num[tb];
		num[tb] = 0;
		if (num[ta] > maxn) maxn = num[ta];
	}
	return ;
}

inline void getd(int &d)
{
	char ch;
	while (!isdigit(ch = getchar())) ;
	d = 0;
	do {
		d *= 10; d += ch - '0';
	} while (isdigit(ch = getchar()));
	return ;
}

int main()
{
	int tmp, i;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 1; i <= n; i++) g[i] = i, num[i] = 1;
		ttl = n; maxn = 1;
		for (i = 1; i <= n; i++)
		{
			getd(tmp);
			uniset(i, tmp);
		}
		printf("%d %d\n", ttl, maxn);
	}
}