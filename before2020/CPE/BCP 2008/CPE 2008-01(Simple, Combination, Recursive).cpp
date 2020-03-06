/**
 *  @judge CPE
 *  @id 2008-01
 *  @tag Simple, Combination, Recursion
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int a[20], n, s;

void dfs(int k)
{
	int i;
	if (k == 0)
	{
		for (i = s; i; i--) printf("%d", a[i]);
		puts("");
		return;
	}
	for (i = a[k + 1] + 1; i <= n; i++)
	{
		a[k] = i;
		dfs(k - 1);
	}
	return;
}

int main()
{
	int ctr;
	for (ctr = 1; cin >> n >> s; ctr++)
	{
		printf("case %d:\n", ctr);
		a[s + 1] = 0;
		if (s) dfs(s);
		puts("");
	}
}