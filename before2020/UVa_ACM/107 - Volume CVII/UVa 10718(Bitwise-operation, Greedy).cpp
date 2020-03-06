/**
 *  @judge UVa
 *  @id 10718
 *  @tag Bitwise Operation, Greedy
 */
#include <stdio.h>
#include <iostream>
#define BIT(i) (1LL << i)
#define OR(x,i) (x | BIT(i))
#define AND(x,i) (x & BIT(i))
using namespace std;

int main()
{
	long long n, L, U, ans, i;
	while (scanf("%lld%lld%lld", &n, &L, &U) != EOF)
	{
		ans = 0;
		for (i = 31; i >= 0; i--)
			if ( OR(ans, i) <= (AND(n, i) ? L: U) ) ans |= BIT(i);
		printf("%lld\n", ans);
	}
}