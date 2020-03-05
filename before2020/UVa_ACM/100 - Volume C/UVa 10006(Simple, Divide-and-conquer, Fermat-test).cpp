#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

#define PMAX 90000
#define SMAX 300
bool ox[PMAX];

void PrimeSieve()
{
	int i, j;
	memset(ox, 1, sizeof(ox));
	ox[1] = 0;
	for (i = 2; i < SMAX; i++)
	{
		if (ox[i])
		{
			for (j = i + i; j < PMAX; j += i)
				ox[j] = 0;
		}
	}
	return ;
}

int PowMod(int a, int p, int m)
{
	long long i, ans;
	i = a % m;
	for (ans = 1; p; p >>= 1)
	{
		if (p & 1) ans *= i;
		ans %= m;
		i = (i * i) % m;
	}
	return (int) ans;
}

int FermatTest(int n)
{
	int i, tmp;
	for (i = 1; i < 15; i++)
	{
		tmp = rand() % (n - 2) + 2;
		if (PowMod(tmp, n, n) != tmp)
			return 0;
	}
	return 1;
}

int main()
{
	int n;
	srand(time(NULL));
	PrimeSieve();
	while (scanf("%d", &n), n)
	{
		if (ox[n]) printf("%d is normal.\n", n);
		else if (FermatTest(n)) printf("The number %d is a Carmichael number.\n", n);
		else printf("%d is normal.\n", n);
	}
}