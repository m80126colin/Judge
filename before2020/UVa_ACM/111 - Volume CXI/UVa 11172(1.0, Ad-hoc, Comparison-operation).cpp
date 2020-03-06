/**
 *  @judge UVa
 *  @id 11172
 *  @tag 1.0, Ad hoc, Comparison operation
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int t, a, b;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d%d", &a, &b);
		if (a == b) puts("=");
		else if (a > b) puts(">");
		else puts("<");
	}
}