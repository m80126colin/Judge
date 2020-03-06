/**
 *  @judge UVa
 *  @id 880
 *  @tag 1.5, Math, Cantor, Triangular number
 */
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

long long n, m, a, b;

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		m = (-1.0 + sqrt(1.0 + 8.0 * (n - 1))) / 2.0;
		b = n - m * (m + 1) / 2;
		a = (m + 2) - b;
		printf("%d/%d\n", a, b);
	}
}