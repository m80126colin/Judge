/**
 *  @judge UVa
 *  @id 11456
 *  @tag 2.5, DP, LIS, LDS
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 2010
int n, a[N], lis[N], lds[N];

int sol()
{
	int i, j;
	for (i = 0; i < n; i++)
		lis[i] = lds[i] = 1;
	for (i = n - 1; i >= 0; i--)
		for (j = n - 1; j > i; j--)
		{
			if (a[j] < a[i])
				lis[i] = max(lis[i], lis[j] + 1);
			if (a[j] > a[i])
				lds[i] = max(lds[i], lds[j] + 1);
		}	
	int ans = 0;
	for (i = 0; i < n; i++)
		ans = max(ans, lis[i] + lds[i] - 1);
	return ans;
}

int main()
{
	int t;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		printf("%d\n", sol());
	}
}