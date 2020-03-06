/**
 *  @judge UVa
 *  @id 10055
 *  @tag 1.0, Ad hoc, Comparison operation
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	long long a, b;
	while (scanf("%lld%lld", &a, &b) != EOF)
		printf("%lld\n", (a > b)? a - b: b - a);
}