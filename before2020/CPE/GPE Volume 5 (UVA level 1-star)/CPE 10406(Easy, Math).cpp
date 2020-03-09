/**
 *  @judge CPE
 *  @id 10406
 *  @source UVa 10041
 * 
 *  @tag Easy, Math
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int abs(int x)
{
	if (x < 0) return -x;
	return x;
}

int main()
{
	int t, r, i, n[510], d;
	for (scanf("%d", &t); t; t--)
	{
		for (scanf("%d", &r), i = 0; i < r; i++) scanf("%d", &n[i]);
		sort(n, n+r);
		for (d = i = 0; i < r; i++) d += abs(n[r/2] - n[i]);
		printf("%d\n", d);
	}
}