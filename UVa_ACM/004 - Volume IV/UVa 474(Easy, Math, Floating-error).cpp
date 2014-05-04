#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
	int n, a;
	double L;
	while (scanf("%d", &n) != EOF)
	{
		L = -n * log10(2.0);
		a = L - 1;
		L -= a;
		printf("2^-%d = %.3lfe%d\n", n, pow(10.0, L) - 1e-9, a);
	}
}