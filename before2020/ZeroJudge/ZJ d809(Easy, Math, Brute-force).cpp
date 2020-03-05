#include <stdio.h>
#include <iostream>
#define N 210
using namespace std;

struct point
{
	int x, y;
}p[N];
int n;
double mx;

inline int Cross(int o, int a, int b)
{
	return (p[a].x - p[o].x) * (p[b].y - p[o].y) - (p[a].y - p[o].y) * (p[b].x - p[o].x);
}

inline int Myabs(int x)
{
	return (x < 0)? -x: x;
}

int main()
{
	int i, j, k, tmp;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)
			scanf("%d%d", &p[i].x, &p[i].y);
		mx = Myabs(Cross(0, 1, 2));
		for (i = 0; i < n; i++)
			for (j = i + 1; j < n; j++)
				for (k = j + 1; k < n; k++)
					if ((tmp = Myabs(Cross(i, j, k))) > mx)
						mx = tmp;
		printf("%.2lf\n", mx / 2.0);
	}
}