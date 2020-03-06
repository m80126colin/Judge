/**
 *  @judge UVa
 *  @id 12468
 *  @tag 1.0, Ad hoc, Min max
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int a, b;
	while (scanf("%d%d", &a, &b), (a != -1 || b != -1))
	{
		if (a < b) swap(a, b);
		printf("%d\n", min(a - b, 100 + b - a));
	}
}