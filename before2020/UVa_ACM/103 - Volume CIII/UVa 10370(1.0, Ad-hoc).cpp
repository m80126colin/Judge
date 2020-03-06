/**
 *  @judge UVa
 *  @id 10370
 *  @tag 1.0, Ad hoc
 */
#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX 1010
int c, n, a[MAX];

int main()
{
	int i, ans, sum;
	for (scanf("%d", &c); c; c--)
	{
		sum = ans = 0;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		for (i = 0; i < n; i++)
			if (a[i] * n > sum) ans++;
		printf("%.3lf%%\n", ans * 100.0 / n);
	}
}