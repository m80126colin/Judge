#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 2
struct Date
{
	int y, m, d;
	bool operator < (const Date &D) const
	{
		if (y != D.y) return y < D.y;
		if (m != D.m) return m < D.m;
		return d < D.d;
	}
	bool operator == (const Date &D) const
	{
		return y == D.y && m == D.m && d == D.d;
	}
}D[MAX];

int main()
{
	int i, t, cnt, ans;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		for (i = 0; i < MAX; i++)
			scanf("%d/%d/%d", &D[i].d, &D[i].m, &D[i].y);
		printf("Case #%d: ", cnt);
		if (D[0] < D[1]) puts("Invalid birth date");
		else
		{
			ans = D[0].y - D[1].y;
			D[1].y += ans;
			while (ans && D[0] < D[1])
			{
				ans--;
				D[1].y--;
			}
			if (ans > 130) puts("Check birth date");
			else printf("%d\n", ans);
		}
	}
}