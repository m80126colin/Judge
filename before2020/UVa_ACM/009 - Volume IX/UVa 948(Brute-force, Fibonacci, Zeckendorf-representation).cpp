/**
 *  @judge UVa
 *  @id 948
 *  @tag Brute force, Fibonacci, Zeckendorf representation
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int f[50], n, i, t, a;
	f[0] = 1, f[1] = 2;
	for (n = 2; f[n-1] < 100000000; n++) f[n] = f[n-1] + f[n-2];
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d", &a);
		printf("%d = ", a);
		for (i = n; i; i--)
		{
			if (a >= f[i-1]) break;
		}
		for (; i; i--)
		{
			if (a >= f[i-1])
			{
				putchar('1');
				a -= f[i-1];
			}
			else putchar('0');
		}
		puts(" (fib)");
	}
}