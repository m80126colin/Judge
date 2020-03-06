/**
 *  @judge CPE
 *  @id 10450
 *  @tag Easy, Prime, Prime factorization
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, i, ctr;
	while (scanf("%d", &n), n)
	{
		printf("%d : ", n);
		for (ctr = 0, i = 2; i < 1000 && n > 1; i++)
		{
			if (!(n % i))
			{
				ctr++;
				n /= i;
				while (!(n % i)) n /= i;
			}
		}
		if (n > 1) ctr++;
		printf("%d\n", ctr);
	}
}