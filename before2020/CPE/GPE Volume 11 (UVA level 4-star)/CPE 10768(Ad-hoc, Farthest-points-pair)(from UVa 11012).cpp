#include <stdio.h>
#include <iostream>
#define N 100010
using namespace std;

struct point
{
	int x, y, z;
}p[N];
int n;

int sol(int a, int b, int c)
{
	int mx, mn, m, i;
	mx = mn = a * p[0].x + b * p[0].y + c * p[0].z;
	for (i = 1; i < n; i++)
	{
		m = a * p[i].x + b * p[i].y + c * p[i].z;
		mx = max(mx, m);
		mn = min(mn, m);
	}
	return mx - mn;
}

int main()
{
	int i, t, ctr;
	for (scanf("%d", &t), ctr = 1; ctr <= t; ctr++)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
		printf("Case #%d: %d\n", ctr, max(max(sol(1, 1, 1), sol(1, 1, -1)), max(sol(1, -1, 1), sol(-1, 1, 1))));
	}
}