/**
 *  @judge UVa
 *  @id 10699
 *  @tag 1.5, Number Theory, Prime sieve, Factorization
 */
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

#define N 1000010
int ox[N];

void sieve()
{
	int i, j;
	for (i = 2; i < N; i++)
		if (ox[i] == 0)
			for (j = i; j < N; j += i)
				ox[j]++;
	return ;
}

int main()
{
	int n;
	sieve();
	while (scanf("%d", &n), n)
		printf("%d : %d\n", n, ox[n]);
}