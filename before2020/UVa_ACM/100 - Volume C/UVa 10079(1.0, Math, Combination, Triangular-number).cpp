/**
 *  @judge UVa
 *  @id 10079
 *  @tag 1.0, Math, Combination, Triangular number
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	long long x;
	while (scanf("%lld", &x), x >= 0)
		printf("%lld\n", ((x * (x + 1)) >> 1) + 1);
}