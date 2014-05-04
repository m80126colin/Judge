#include <stdio.h>
#include <iostream>
using namespace std;

inline long long collatz(long long n)
{
	long long s, tmp = n;
	tmp = ((tmp & 1) ? (3 * tmp + 1): (tmp >> 1));
	for (s = 1; tmp != 1; s++)
		tmp = ((tmp & 1) ? (3 * tmp + 1): (tmp >> 1));
	return s;
}

int main()
{
	long long l, h, s, v, ts, tmp;
	while (scanf("%lld%lld", &l, &h), (l || h))
	{
		if (l > h) swap(l, h);
		s = collatz(l);
		v = l;
		for (tmp = l; ++tmp <= h; )
		{
			ts = collatz(tmp);
			if (ts > s) s = ts, v = tmp;
		}
		printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n", l, h, v, s);
	}
}