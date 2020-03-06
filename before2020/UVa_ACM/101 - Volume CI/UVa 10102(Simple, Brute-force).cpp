/**
 *  @judge UVa
 *  @id 10102
 *  @tag Simple, Brute force
 */
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

struct point
{
	int x, y;
	point (int x, int y): x(x), y(y) {}
};
int m;
vector<point> A, C;

inline int abs(int x)
{
	if (x > 0) return x;
	return -x;
}

inline int dis(point a, point b)
{
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int sol()
{
	int i, j, ans, tmp;
	ans = 0;
	for (i = 0; i < A.size(); i++)
	{
		tmp = dis(A[i], C[0]);
		for (j= 1; j < C.size(); j++)
			tmp = min(tmp, dis(A[i], C[j]));
		ans = max(ans, tmp);
	}
	return ans;
}

int main()
{
	char ch;
	int i, j;
	while (scanf("%d", &m) != EOF)
	{
		getchar();
		A.clear();
		C.clear();
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < m; j++)
			{
				ch = getchar();
				if (ch == '1') A.push_back(point(i, j));
				if (ch == '3') C.push_back(point(i, j));
			}
			getchar();
		}
		printf("%d\n", sol());
	}
}