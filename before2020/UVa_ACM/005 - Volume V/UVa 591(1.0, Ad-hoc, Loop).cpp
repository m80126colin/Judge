/**
 *  @judge UVa
 *  @id 591
 *  @tag 1.0, Ad-hoc, Loop
 */
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 60
int n, a[MAX];

int main()
{
	int i, t, sum, ans;
	for (t = 1; scanf("%d", &n), n; t++)
	{
		for (sum = i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		sum /= n;
		for (ans = i = 0; i < n; i++)
			if (a[i] > sum) ans += (a[i] - sum);
		printf("Set #%d\nThe minimum number of moves is %d.\n\n", t, ans);
	}
}