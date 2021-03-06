/**
 *  @judge ZeroJudge
 *  @id d186
 *  @source UVa 11461
 * 
 *  @tag Easy, Math, Number Theory
 */
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
	int a, b;
	while (scanf("%d%d", &a, &b) && (a || b))
	{
		a = ceil(sqrt((double) a));
		b = floor(sqrt((double) b));
		printf("%d\n", b - a + 1);
	}
}