/**
 *  @judge TIOJ
 *  @id 1178
 *  @tag Convex hull
 */
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <ctype.h>
#define N 200010
using namespace std;

inline void getd(int &d)
{
	int flag = 0;
	char ch;
	while (!isdigit(ch = getchar()))
		if (ch == '-') flag = 1;
	d = 0;
	do {
		d *= 10; d += ch - '0';
	} while (isdigit(ch = getchar()));
	if (flag) d = -d;
	return ;
}

struct point
{
	int x, y;
};

inline bool convex_cmp(point left, point right)
{
	return left.x < right.x;
}

class ConvexHull
{
public:
	int n, m;
	point vertex[N], convex[N];
	inline long long cross(point o, point a, point b)
	{
		return (long long) (a.x - o.x) * (b.y - o.y) - (long long) (a.y - o.y) * (b.x - o.x);
	}
	inline void convex_hull()
	{
		int i, j;
		sort(vertex, vertex + n, convex_cmp);
		for (i = m = 0; i < n; i++)
		{
			while (m >= 2 && cross(convex[m - 2], convex[m - 1], vertex[i]) >= 0) m--;
			convex[m++] = vertex[i];
		}
		for (i = n - 2, j = m + 1; i >= 0; i--)
		{
			while (m >= j && cross(convex[m - 2], convex[m - 1], vertex[i]) >= 0) m--;
			convex[m++] = vertex[i];
		}
		m--;
	}
	inline int convex_dot()
	{
		return m;
	}
};

ConvexHull CH;

int main()
{
	int i;
	while (scanf("%d", &CH.n) != EOF)
	{
		for (i = 0; i < CH.n; i++)
			getd(CH.vertex[i].x), getd(CH.vertex[i].y);
		CH.convex_hull();
		printf("%d\n", CH.convex_dot());
	}
}