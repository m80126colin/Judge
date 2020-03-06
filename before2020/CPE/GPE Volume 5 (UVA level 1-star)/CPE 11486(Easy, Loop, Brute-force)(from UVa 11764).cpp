/**
 *  @judge CPE
 *  @id 11486
 *  @tag Easy, Loop, Brute force
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
	int t, ctr, be, af, up, dn, i, n;
	for (cin >> t, ctr = 1; ctr <= t; ctr++)
	{
		cin >> n >> be;
		up = dn = 0;
		for (i = 1; i < n; i++)
		{
			cin >> af;
			if (be > af) dn++;
			else if (be < af) up++;
			be = af;
		}
		printf("Case %d: %d %d\n", ctr, up, dn);
	}
}