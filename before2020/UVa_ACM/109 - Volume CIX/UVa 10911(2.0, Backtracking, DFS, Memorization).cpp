#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

#define MAXN 8
#define MAXS 10
#define MAXP (MAXS << 1)
#define MAXC 110
struct student
{
	int x, y;
}Stu[MAXP];
int n, p[MAXP];
char name[MAXC];
double mn;
double distable[MAXP][MAXP];

struct partner
{
	int a[MAXP];
};
partner tmp;
vector<partner> Pair[MAXS];

void Partner(int x)
{
	if (x >= n)
	{
		Pair[n].push_back(tmp);
		return ;
	}
	int i, j;
	for (i = 0; i < 2 * n; i++)
		if (!p[i]) break;
	p[i] = 1;
	tmp.a[2 * x] = i;
	for (j = 0; j < 2 * n; j++)
		if (!p[j])
		{
			p[j] = 1;
			tmp.a[2 * x + 1] = j;
			Partner(x + 1);
			tmp.a[2 * x + 1] = 0;
			p[j] = 0;
		}
	tmp.a[2 * x] = 0;
	p[i] = 0;
	return ;
}

double dis(partner PP)
{
	int i;
	double ans = 0.0;
	for (i = 0; i < n; i++)
		ans += distable[PP.a[2 * i]][PP.a[2 * i + 1]];
	return ans;
}

int main()
{
	int t, i, j;
	for (n = 1; n <= MAXN; n++)
	{
		memset(p, 0, sizeof(p));
		Partner(0);
	}
	for (t = 1; scanf("%d", &n), n; t++)
	{
		for (i = 0; i < 2 * n; i++)
			scanf("%s%d%d", name, &Stu[i].x, &Stu[i].y);
		for (i = 0; i < 2 * n; i++)
			for (j = i + 1; j < 2 * n; j++)
				distable[i][j] = sqrt((double) (Stu[i].x - Stu[j].x) * (Stu[i].x - Stu[j].x) + (Stu[i].y - Stu[j].y) * (Stu[i].y - Stu[j].y));
		mn = 10000.0;
		for (i = 0; i < Pair[n].size(); i++)
			mn = min(mn, dis(Pair[n][i]));
		printf("Case %d: %.2lf\n", t, mn);
	}
}