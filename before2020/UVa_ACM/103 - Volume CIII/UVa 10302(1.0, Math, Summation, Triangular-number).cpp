/**
 *  @judge UVa
 *  @id 10302
 *  @tag 1.0, Math, Summation, Triangular number
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	long long n;
	while (scanf("%lld", &n) != EOF)
		printf("%lld\n", n * n * (n + 1) * (n + 1) / 4);
}