#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#define N 10000010
#define sqtN 3162
using namespace std;

bool sieve[N];
vector <int> prime;

inline int isprime(long long p)
{
	if (p < 2 || p % 2 == 0) return 0;
	int i, m = sqrt((double) p);
	for (i = 0; i < prime.size() && prime[i] <= p; i++)
		if (p % prime[i] == 0)
			return 0;
	return 1;
}

int main()
{
	int i, j, cnt, ans;
	long long n;
	sieve[1] = 1;
	for (i = 2; i <= sqtN; i++)
	{
		if (!sieve[i])
		{
			prime.push_back(i);
			for (j = 2; i * j < N; j++)
				sieve[i * j] = 1;
		}
	}
	for (; i < N; i++)
		if (!sieve[i])
			prime.push_back(i);
	while (scanf("%lld", &n), n)
	{
		if (n < 0) n = -n;
		if (n < 4 || (n < N && (!sieve[n])) || isprime(n))
			puts("-1");
		else
		{
			cnt = ans = 0;
			for (i = 0; i < prime.size() && prime[i] <= n; i++)
			{
				if (n % prime[i] == 0) cnt++, ans = prime[i];
				for (; n % prime[i] == 0; n /= prime[i]);
			}
			if (n == 1)
			{
				if (cnt > 1) printf("%d\n", ans);
				else puts("-1");
			}
			else
			{
				if (cnt) printf("%lld\n", n);
				else puts("-1");
			}
		}
	}
}