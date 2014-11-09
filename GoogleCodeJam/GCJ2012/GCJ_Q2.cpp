#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct triple
{
	int m, j, k;
}Triple[110];

bool cmp(triple left, triple right)
{
	if (left.j != right.j)
		return left.j < right.j;
	return left.k < right.k;
}

int main()
{
	//freopen("B-large.in","r+",stdin);
	//freopen("B-large.out","w+",stdout);
	int i, ans;
	int t, ctr;
	int n, s, p;
	for (scanf("%d", &t), ctr = 1; ctr <= t; ctr++)
	{
		scanf("%d%d%d", &n, &s, &p);
		for (i = 0; i < n; i++)
		{
			scanf("%d", &Triple[i].m);
			Triple[i].j = Triple[i].m / 3;
			Triple[i].k = Triple[i].m % 3;
		}
		sort(Triple, Triple + n, cmp);
		for (i = ans = 0; i < n; i++)
		{
			if (Triple[i].j + 2 == p)
			{
				if (s && Triple[i].k == 2)
				{
					s--;
					ans++;
				}
			}
			else if (Triple[i].j + 1 == p)
			{
				if (Triple[i].k == 0)
				{
					if (s && Triple[i].j >= 1)
					{
						s--;
						ans++;
					}
				}
				else ans++;
			}
			else if (Triple[i].j >= p)
				ans++;
		}
		printf("Case #%d: %d\n", ctr, ans);
	}
}