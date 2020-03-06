/**
 *  @judge UVa
 *  @id 10110
 *  @tag 1.0, Math, Square root
 */
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
	long long n, m;
	while (scanf("%lld", &n), n)
	{
		m = sqrt((double) n);
		if (m * m == n) puts("yes");
		else puts("no");
	}
}