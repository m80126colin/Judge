#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int t, n, a;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d", &n);
		for (a = 0; a <= 10; a++)
			if (n - a <= 10) break;
		printf("%d %d\n", a, n - a);
	}
}