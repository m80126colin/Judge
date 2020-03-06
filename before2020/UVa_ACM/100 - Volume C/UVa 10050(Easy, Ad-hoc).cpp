/**
 *  @judge UVa
 *  @id 10050
 *  @tag Easy, Ad hoc
 */
#include <stdio.h>
#include <iostream>
using namespace std;


#define MAX 110
int t, n, p, d[MAX];

int Test(int x)
{
	int i, y = x % 7;
	if (y == 5 || y == 6) return 0;
	y = x + 1;
	for (i = 0; i < p; i++)
		if (y % d[i] == 0) return 1;
	return 0;
}

int main()
{
	int i, ans;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d%d", &n, &p);
		for (i = 0; i < p; i++)
			scanf("%d", &d[i]);
		for (i = ans = 0; i < n; i++)
			if (Test(i)) ans++;
		printf("%d\n", ans);
	}
}