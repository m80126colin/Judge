#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define N 1000000
bool ox[N];
int pr[N], pn;

void sieve()
{
	int i, j;
	memset(ox, 1, sizeof(ox));
	ox[0] = ox[1] = 0;
	for (i = 2; i < N; i++)
	{
		if (ox[i]) pr[pn++] = i;
		for (j = 0; j < pn && i * pr[j] < N; j++)
			ox[i * pr[j]] = 0;
	}
}

int reverse(int n)
{
	int res = 0;
	while (n)
	{
		res *= 10;
		res += n % 10;
		n /= 10;
	}
	return res;
}

void sol(int n)
{
	int res;
	if (ox[n])
	{
		res = reverse(n);
		if (n != res && ox[res]) printf("%d is emirp.\n", n);
		else printf("%d is prime.\n", n);
	}
	else printf("%d is not prime.\n", n);
	return ;
}

int main()
{
	int n;
	sieve();
	while (scanf("%d", &n) != EOF)
		sol(n);
}