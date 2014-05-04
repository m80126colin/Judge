#include <stdio.h>
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	return (b)? gcd(b, a%b): a;
}

int main()
{
	int t, a, b, g;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d%d", &a, &b);
		g = gcd(a, b);
		printf("%d/%d\n", a/g, b/g);
	}
}