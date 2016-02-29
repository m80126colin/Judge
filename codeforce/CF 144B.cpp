#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

struct point
{
	int x, y;
}r1, r2, c[1010], p[10010];

int n, m, ox[10010], r[1010];

int main()
{
	int i, j;
	while (scanf("%d%d%d%d", &r1.x, &r1.y, &r2.x, &r2.y) != EOF)
	{
		if (r1.x > r2.x) swap(r1.x, r2.x);
		if (r1.y > r2.y) swap(r1.y, r2.y);
		m = 0;
		for (i = r1.x + 1; i <= r2.x; i++) 
		{
			p[m].x = i;
			p[m++].y = r1.y;
		}
		for (i = r1.y + 1; i <= r2.y; i++) 
		{
			p[m].x = r2.x;
			p[m++].y = i;
		}
		for (i = r2.x - 1; i >= r1.x; i--) 
		{
			p[m].x = i;
			p[m++].y = r2.y;
		}
		for (i = r2.y - 1; i >= r1.y; i--) 
		{
			p[m].x = r1.x;
			p[m++].y = i;
		}
		memset(ox, 0, sizeof(ox));
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d%d%d", &c[i].x, &c[i].y, &r[i]);
			for (j = 0; j < m; j++)
			{
				if (!ox[j])
				{
					if ((c[i].x - p[j].x) * (c[i].x - p[j].x) + (c[i].y - p[j].y) * (c[i].y - p[j].y) <= r[i] * r[i]) ox[j] = 1;
				}
			}
		}
		int ans = 0;
		for (j = 0; j < m; j++)
		{
			if (!ox[j]) ans++;
		}
		printf("%d\n", ans);
	}
}