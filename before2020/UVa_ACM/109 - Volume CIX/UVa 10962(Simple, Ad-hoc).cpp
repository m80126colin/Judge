/**
 *  @judge UVa
 *  @id 10962
 *  @tag Simple, Ad hoc
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define MAX 2010
#define EPS 1e-8
int R, r, N, C;
int s[MAX], g[MAX];
double eat[MAX], begin[MAX], end[MAX], c;

int main()
{
	int t, i, j;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d%d%d%d", &R, &r, &N, &C);
		eat[0] = begin[0] = end[0] = 0.0;
		for (i = 1; i <= N; i++)
		{
			scanf("%d%d", &s[i], &g[i]);
			eat[i] = eat[i - 1] + 1.0 * g[i] / R;
			begin[i] = max(end[i - 1], eat[i]);
			end[i] = begin[i] + 1.0 * (s[i] - g[i]) / r;
		}
		j = 1;
		for (i = 0; i < C; i++)
		{
			scanf("%lf", &c);
			while (j <= N && end[j] + EPS < c) j++;
			if (j > N)
			{
				puts("clear");
				continue;
			}
			if (c < begin[j] - EPS) puts("clear");
			else if (begin[j] - EPS <= c && c <= end[j] + EPS) puts("full");
			else puts("clear");
		}
		if (t > 1) puts("");
	}
}