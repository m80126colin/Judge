/**
 *  @judge UVa
 *  @id 10856
 *  @tag Prime, Factorization
 */
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

#define MAX 10000001
#define PMAX 2703663
#define SMAX sqrt((double) PMAX)

int p[PMAX + 1], tot[MAX + 1], last;

int main()
{
	unsigned int i, j, k;
	p[0] = p[1] = 0;
	last = 0;
	for (i = 2; i <= PMAX; i++)
	{
		if (!p[i])
		{
			for (j = i; j <= PMAX; j *= i)
			{
				for (k = 1; k * j <= PMAX; k++)
					p[k * j]++;
				if (i > 1644 || j * i > PMAX) break;
			}
		}
		if (last + p[i] <= MAX) tot[last + p[i]] = i;
		last += p[i];
	}
	int t, n;
	for (t = 1; scanf("%d", &n), n >= 0; t++)
	{
		printf("Case %d: ", t);
		if (n == 0) puts("0!");
		else if (tot[n]) printf("%d!\n", tot[n]);
		else puts("Not possible.");
	}
}