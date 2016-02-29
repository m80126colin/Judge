#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

long long a, b;

int main()
{
	while (scanf("%lld %lld", &a, &b) != EOF)
	{
		putchar('[');
		printf("%d;", a / b);
		a %= b;
		for (int i = 0; a; i++)
		{
			swap(a, b);
			if (i) putchar(',');
			printf("%d", a / b);
			a %= b;
		}
		putchar(']');
		puts("");
	}
}