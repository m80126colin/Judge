#include <stdio.h>
#include <iostream>
#include <math.h>
#define N 15
using namespace std;

struct point
{
	double x, y;
	point() {}
	point(double _x, double _y): x(_x), y(_y) {}
	bool operator != (const point &a)
	{
		return (x != a.x) || (y != a.y);
	}
}tmp;
struct graph
{
	char type;
	double radius;
	point center, a, b;
}g[N];
int n;

inline int input()
{
	char ch;
	for (n = 0; (ch = getchar()) && ch != '*'; n++)
	{
		if (ch == EOF) return 0;
		g[n].type = ch;
		if (ch == 'r')
		{
			scanf("%lf%lf%lf%lf", &g[n].a.x, &g[n].a.y, &g[n].b.x, &g[n].b.y);
			if (g[n].a.x > g[n].b.x) swap(g[n].a.x, g[n].b.x);
			if (g[n].a.y > g[n].b.y) swap(g[n].a.y, g[n].b.y);
		}
		else if (ch == 'c')
			scanf("%lf%lf%lf", &g[n].center.x, &g[n].center.y, &g[n].radius);
		else scanf("%lf%lf%lf%lf%lf%lf", &g[n].a.x, &g[n].a.y, &g[n].b.x, &g[n].b.y, &g[n].center.x, &g[n].center.y);
		ch = getchar();
	}
	return 1;
}

inline double dis2(const point &a, const point &b)
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

inline double cross(const point &o, const point &a, const point &b)
{
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

inline bool fit(int index, const point &a)
{
	graph *ptr = &g[index];
	if (ptr -> type == 'r')
		return (ptr -> a.x) < a.x && (ptr -> b.x) > a.x && (ptr -> a.y) < a.y && (ptr -> b.y) > a.y;
	else if (ptr -> type == 'c')
		return dis2(ptr -> center, a) < (ptr -> radius) * (ptr -> radius);
	else if (ptr -> type == 't')
	{
		double x, y, z;
		x = cross(ptr -> a, ptr -> b, a);
		y = cross(ptr -> b, ptr -> center, a);
		z = cross(ptr -> center, ptr -> a, a);
		return (x < 0 && y < 0 && z < 0) || (x > 0 && y > 0 && z > 0);
	}
	return 0;
}

int main()
{
	int i, j, flag;
	while (input())
		for (i = 1; scanf("%lf%lf", &tmp.x, &tmp.y), tmp != point(9999.9, 9999.9); i++)
		{
			flag = 1;
			for (j = 0; j < n; j++) if (fit(j, tmp)) printf("Point %d is contained in figure %d\n", i, j + 1), flag = 0;
			if (flag) printf("Point %d is not contained in any figure\n", i);
		}
}