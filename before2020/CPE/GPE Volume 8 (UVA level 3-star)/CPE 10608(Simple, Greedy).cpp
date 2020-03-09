/**
 *  @judge CPE
 *  @id 10608
 *  @source UVa 10020
 * 
 *  @tag Simple, Greedy
 */
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int m, t;

#define MAX 110000
struct seg
{
	int x, y;
}s[MAX];
int now;

bool cmp(seg A, seg B)
{
	if (A.x != B.x) return A.x < B.x;
	return A.y > B.y;
}

int main()
{
	int n, i, j;
	for (cin >> n; n; n--)
	{
		cin >> m;
		for (t = 0; ; t++)
		{
			scanf("%d %d", &s[t].x, &s[t].y);
			if (s[t].x == 0 && s[t].y == 0)
				break;
			if (s[t].x > m || s[t].y <= 0)
			{
				t--;
				continue;
			}
		}
		if (t == 0)
			puts("0");
		else
		{
			sort(s, s+t, cmp);
			vector<int> L;
			L.clear();
			int mx;
			now = -1;
			if (s[0].x <= 0)
			{
				mx = 0;
				i = 0;
				for (j = 0; j < t; j++)
				{
					if (s[j].x <= 0)
					{
						if (s[j].y > mx)
						{
							mx = s[j].y;
							i = j;
						}
					}
					else break;
				}
				L.push_back(i);
				now = i;
				while (1)
				{
					mx = 0;
					if (s[now].y >= m)
						break;
					i = t;
					for (j = now + 1; j < t; j++)
					{
						if (s[j].x <= s[now].y)
						{
							if (s[j].y - s[now].y >= mx)
							{
								i = j;
								mx = s[j].y - s[now].y;
							}
						}
						else break;
					}
					if (i == t)
					{
						if (s[now].y < m)
							L.clear();
						break;
					}
					L.push_back(i);
					now = i;
				}

			}
			printf("%d\n", L.size());
			for (i = 0; i < L.size(); i++)
				printf("%d %d\n", s[L[i]].x, s[L[i]].y);
		}
		if (n > 1) puts("");
	}
}