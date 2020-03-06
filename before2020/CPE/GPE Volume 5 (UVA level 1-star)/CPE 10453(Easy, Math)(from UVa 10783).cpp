/**
 *  @judge CPE
 *  @id 10453
 *  @tag Easy, Math
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a, b, ctr, t;
	scanf("%d", &t);
	for (ctr = 1; ctr <= t; ctr++)
	{
		scanf("%d%d", &a, &b);
		if (a > b) swap(a, b);
		a += ( !(a & 1) );
		b -= ( !(b & 1) );
		printf("Case %d: %d\n", ctr, ((b - a) / 2 + 1) * (a + b) / 2);
	}
}