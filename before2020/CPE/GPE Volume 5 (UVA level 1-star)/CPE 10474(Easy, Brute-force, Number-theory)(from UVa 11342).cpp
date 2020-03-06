/**
 *  @judge CPE
 *  @id 10474
 *  @tag Easy, Brute force, Number Theory
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isdepos(int n)
{
	int i, j, k;
	for (i = 0; i * i <= n; i++)
	{
		for (j = i; i * i + j * j <= n; j++)
		{
			k = sqrt((double) n - i * i - j * j);
			if (k * k == n - i * i - j * j)
			{
				printf("%d %d %d\n", i, j, k);
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int n, k;
	for (cin >> n; n; n--)
	{
		cin >> k;
		if (!isdepos(k)) puts("-1");
	}
}