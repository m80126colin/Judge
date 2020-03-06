/**
 *  @judge ZeroJudge
 *  @id a216
 *  @tag 1.0, Math, Summation
 */
#include <stdio.h>
#include <iostream>
using namespace std;

#define F(x) ((long long) (x) * ((x) + 1) / 2)
#define G(x) ((long long) (x) * ((x) + 1) * ((x) + 2) / 6)

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
		printf("%lld %lld\n", F(n), G(n));
}