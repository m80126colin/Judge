#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int A, B;
int ctr, t, i, j;
double cor[100010];

double sol()
{
	double ans = 0, res[100010];
	memset(res, 0, sizeof(res));
	res[0] = 1.0;
	for (i = 1; i <= A; i++)
		res[i] = res[i - 1] * cor[i - 1];
	ans = B + 2;
	for (i = A; i; i--)
		ans = min(ans, (B + A - 2 * i + 1) + (1.0 - res[i]) * (B + 1) );
	return ans;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("1A_Q1_large.out", "w+", stdout);
	scanf("%d", &t);
	for (ctr = 1; ctr <= t; ctr++)
	{
		scanf("%d%d", &A, &B);
		memset(cor, 0, sizeof(cor));
		for (i = 0; i < A; i++)
			scanf("%lf", &cor[i]);
		printf("Case #%d: %.6lf\n", ctr, sol());
	}
}