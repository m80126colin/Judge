/**
 *  @judge CPE
 *  @id 10454
 *  @source UVa 10812
 * 
 *  @tag Easy, Brute force, Math
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

long long a, b;

bool isdepos()
{
	if (((a+b) & 1) || (a-b) < 0) return 0;
	printf("%lld %lld\n", (a+b)/2, (a-b)/2);
	return 1;

}

int main()
{
	int n;
	for (cin >> n; n; n--)
	{
		cin >> a >> b;
		if (!isdepos()) puts("impossible");
	}
}