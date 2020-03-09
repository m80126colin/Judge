/**
 *  @judge CPE
 *  @id 10468
 *  @source UVa 11059
 * 
 *  @tag Easy, Brute force
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	long long ctr, n, a[19], i, j, sum, tmp;
	for (ctr = 1; cin >> n; ctr++)
	{
		sum = 0;
		for (i = 0; i < n; i++) cin >> a[i];
		for (i = 0; i < n; i++)
		{
			tmp = a[i];
			sum = max(sum, tmp);
			for (j = i+1; j < n; j++)
			{
				tmp *= a[j];
				sum = max(sum, tmp);
			}
		}
		printf("Case #%lld: The maximum product is %lld.\n", ctr, sum);
		puts("");
	}
}