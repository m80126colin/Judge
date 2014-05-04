#include <stdio.h>
#include <iostream>
using namespace std;

inline long long collatz(long long n, long long lim)
{
	long long ans, tmp = n;
	for (ans = 1; tmp != 1 && tmp <= lim; ans++)
		tmp = ((tmp & 1) ? (3 * tmp + 1): (tmp >> 1));
	if (tmp > lim) ans--;
	return ans;
}

int main()
{
	int t;
	long long A, L;
	for (t = 1; scanf("%lld%lld", &A, &L), (A >= 0 || L >= 0); t++)
		printf("Case %d: A = %lld, limit = %lld, number of terms = %lld\n", t, A, L, collatz(A, L));
}