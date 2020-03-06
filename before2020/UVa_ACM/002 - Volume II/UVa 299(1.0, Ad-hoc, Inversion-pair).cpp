/**
 *  @judge UVa
 *  @id 299
 *  @tag 1.0, Ad hoc, Inversion pair
 */
#include <iostream>
#include <stdio.h>
#define M 170
using namespace std;

int a[M], n;

int main()
{
	int i, j, t, ans;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (i = ans = 0; i < n; i++)
			for (j = i + 1; j < n; j++)
				if (a[i] > a[j])
					ans++;
		printf("Optimal train swapping takes %d swaps.\n", ans);
	}
}