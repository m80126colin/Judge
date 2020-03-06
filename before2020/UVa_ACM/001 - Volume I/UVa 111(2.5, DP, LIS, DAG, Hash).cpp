/**
 *  @judge UVa
 *  @id 111
 *  @tag 2.5, DP, LIS, DAG, Hash
 */
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 30
int n, a[MAX], b[MAX];

int input(int *arr)
{
	int i;
	for (i = 0; i < n; i++)
		if (scanf("%d", &arr[i]) == EOF) return 0;
	return 1;
}

int trans(int *arr)
{
	int i, tmp[MAX];
	for (i = 0; i < n; i++)
		tmp[a[i] - 1] = arr[i] - 1;
	for (i = 0; i < n; i++)
		arr[tmp[i]] = i;
	return 0;
}

int LIS(int *arr)
{
	int i, j, ans, dp[MAX];
	for (i = 0; i < n; i++)
		dp[i] = 1;
	ans = 1;
	for (i = 0; i < n; i++)
		for (j = 0; j < i; j++)
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
	for (i = 0; i < n; i++)
		ans = max(ans, dp[i]);
	return ans;
}

int main()
{
	for (scanf("%d", &n), input(a); input(b); printf("%d\n", LIS(b)))
		trans(b);
}