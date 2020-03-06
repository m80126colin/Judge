/**
 *  @judge UVa
 *  @id 408
 *  @tag Easy, Gcd, Number Theory
 */
#include <stdio.h>
#include <iostream>
using namespace std;

inline int gcd(int a, int b)
{
	return (a % b) ? gcd(b, a % b): b;
}

int main()
{
	int SEED, STEP;
	while (scanf("%d%d", &SEED, &STEP) != EOF)
	{
		printf("%10d%10d    ", SEED, STEP);
		if (gcd(SEED, STEP) == 1) puts("Good Choice");
		else puts("Bad Choice");
		puts("");
	}
}