/**
 *  @judge CPE
 *  @id 10436
 *  @source UVa 10310
 * 
 *  @tag Easy, Geometry
 */
#include <stdio.h>
#include <math.h>
#include <iostream>
#define N 1010
using namespace std;

struct point
{
	double x, y;
}G, D, H[N];

inline double F(const point& a, const point& b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{
	int n, i;
	while (scanf("%d", &n) != EOF)
	{
		scanf("%lf%lf%lf%lf", &G.x, &G.y, &D.x, &D.y);
		for (i = 0; i < n; i++)
			scanf("%lf%lf", &H[i].x, &H[i].y);
		for (i = 0; i < n; i++)
			if (F(G, H[i]) * 2 <= F(D, H[i])) break;
		if (i == n) puts("The gopher cannot escape.");
		else printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n", H[i].x, H[i].y);
	}
}