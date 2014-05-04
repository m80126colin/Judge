#include <stdio.h>
#include <iostream>
using namespace std;

inline int gcd(int a, int b)
{
	return (b)? gcd(b, a % b): a;
}
int n, g;

int main()
{
	int i, j;
	while (scanf("%d", &n) != EOF)
	{
		scanf("%d", &g);
		for (i = 1; i < n; i++)
			scanf("%d", &j), g = gcd(g, j);
		printf("%d\n", g);
	}
}