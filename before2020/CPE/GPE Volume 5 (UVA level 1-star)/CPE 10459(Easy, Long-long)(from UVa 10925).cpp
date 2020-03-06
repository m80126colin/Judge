/**
 *  @judge CPE
 *  @id 10459
 *  @tag Easy, Long long
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	long long sum, tmp;
	int n, f, i, ctr;
	for (ctr = 1; scanf("%d%d", &n, &f), (n || f); ctr++)
	{
		sum = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%lld", &tmp);
			sum += tmp;
		}
		printf("Bill #%d costs %lld: each friend should pay %lld\n\n", ctr, sum, sum / f);
	}
}