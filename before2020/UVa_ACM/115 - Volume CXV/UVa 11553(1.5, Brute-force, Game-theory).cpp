/**
 *  @judge UVa
 *  @id 11553
 *  @tag 1.5, Brute force, Game theory
 */
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10
int t, n, m[MAX][MAX], v[MAX], tmp, ans;

int main()
{
	int i, j, flag;
	for (scanf("%d", &t); t; t--)
	{
		flag = 1;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				scanf("%d", &m[i][j]);
		ans = 0;
		for (i = 0; i < n; i++)
			v[i] = i;
		do {
			tmp = 0;
			for (i = 0; i < n; i++)
				tmp += m[i][v[i]];
			if (flag)
			{
				ans = tmp;
				flag = 0;
			}
			else if (tmp < ans)
				ans = tmp;
		} while ( next_permutation(v, v + n) );
		printf("%d\n", ans);
	}
}