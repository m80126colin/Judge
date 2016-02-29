#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 210
int t, r, a[MAX];

int main()
{
	int i, ans;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d", &r);
		for (i = 0; i < r; i++)
			scanf("%d", &a[i]);
		sort(a, a + r);
		for (i = ans = 0; i < r; i++)
			ans += (abs(a[i] - a[r / 2]));
		printf("%d\n", ans);
	}
}