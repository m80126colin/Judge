/**
 *  @judge UVa
 *  @id 11428
 *  @tag Easy, Math
 */
#include <stdio.h>
#include <iostream>
#include <map>
#define cube(x) (x * x * x)
using namespace std;

map <int, int> cb;

int main()
{
	int i, n;
	cb.clear();
	for (i = 1; i <= 61; i++)
		cb[cube(i)] = i;
	while (scanf("%d", &n), n)
	{
		for (i = 1; i < 61; i++)
			if (cb[n + cube(i)])
			{
				printf("%d %d\n", cb[n + cube(i)], i);
				break;
			}
		if (i == 61) puts("No solution");
	}
}