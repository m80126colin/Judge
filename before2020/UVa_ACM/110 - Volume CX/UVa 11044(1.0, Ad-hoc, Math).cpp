#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int m, n, t;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d%d", &m, &n);
		printf("%d\n", (m / 3) * (n / 3));
	}
}