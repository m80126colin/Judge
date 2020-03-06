/**
 *  @judge ZeroJudge
 *  @id d186
 *  @tag Easy, Brute force, Number theory
 */
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
	int a, b, i, j, ans;
	while (scanf("%d%d", &a, &b) && (a || b))
	{
		ans = 0;
		for (i = a; i <= b; i++)
		{
			j = sqrt((double) i);
			if (j * j == i) ans++;
		}
		printf("%d\n", ans);
	}
}