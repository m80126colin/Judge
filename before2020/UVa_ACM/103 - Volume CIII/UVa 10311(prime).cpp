/**
 *  @judge UVa
 *  @id 10311
 *  @tag prime
 */
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <map>
#include <math.h>
using namespace std;

map<int, int> M;

inline int isprime(int x)
{
	if (x < 2) return 0;
	if (M[x]) return M[x] > 1;
	int y = sqrt((double) x);
	for (int i = 2; i <= y; i++)
	{
		if (!(x % i)) {
			M[x] = 1;
			return 0;
		}
	}
	M[x] = 2;
	return 1;
}

int main()
{
	int n, t;
	M.clear();
	M[1] = 1;
	while (scanf("%d", &n) != EOF)
	{
		if (n & 1)
		{
			if (isprime(n - 2)) printf("%d is the sum of 2 and %d.\n", n, n - 2);
			else printf("%d is not the sum of two primes!\n", n);
		}
		else
		{
			t = n / 2;
			if (!(t & 1)) t--;
			for (; t > 2; t -= 2)
			{
				if (t >= n - t) continue;
				if (isprime(t) && isprime(n - t))
				{
					printf("%d is the sum of %d and %d.\n", n, t, n - t);
					break;
				}
			}
			if (t <= 2) printf("%d is not the sum of two primes!\n", n);
		}
	}
}