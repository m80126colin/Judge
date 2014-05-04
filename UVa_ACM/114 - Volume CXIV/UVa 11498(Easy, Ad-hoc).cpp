#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

struct point
{
	int x, y;
	point () {}
	point (int x, int y): x(x), y(y) {}
	point operator - (const point &a)
	{
		return point(x - a.x, y - a.y);
	}
}P[1010], X;
string D[5] = {"divisa", "SO", "SE", "NO", "NE"};

inline int dir(const point &a)
{
	int ans = 0;
	if (a.x == 0 || a.y == 0) ans = -1;
	else
	{
		ans |= (a.x > 0);
		ans |= ((a.y > 0) << 1);
	}
	return ans + 1;
}

int main()
{
	int i, k;
	while (scanf("%d", &k), k)
	{
		scanf("%d%d", &X.x, &X.y);
		for (i = 0; i < k; i++)
			scanf("%d%d", &P[i].x, &P[i].y);
		for (i = 0; i < k; i++)
			cout << D[dir(P[i] - X)] << endl;
	}
}