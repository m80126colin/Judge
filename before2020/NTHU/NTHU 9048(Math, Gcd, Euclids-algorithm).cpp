/**
 *  @judge NTHU
 *  @id 9048
 *  @tag Math, Gcd, Euclids algorithm
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

inline int gcd(int a, int b)
{
	return (b)? gcd(b, a%b): a;
}

int main()
{
	int t,a, b;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d%d", &a, &b);
		printf("%d\n", gcd(a, b));
	}
}