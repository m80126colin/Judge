#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

#define SOL(x) ((-1.0 + sqrt(8.0 * (x))) / 2.0)
int n, r, t, a, b;

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		printf("TERM %d IS ", n);
		r = SOL(n);
		t = n - r * (r + 1) / 2;
		a = (r + 2) - t;
		b = t;
		if (r & 1) swap(a, b);
		printf("%d/%d\n", a, b);
	}
}