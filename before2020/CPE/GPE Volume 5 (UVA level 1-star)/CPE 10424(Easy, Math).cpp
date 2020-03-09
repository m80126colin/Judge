/**
 *  @judge CPE
 *  @id 10424
 *  @source UVa 10221
 * 
 *  @tag Easy, Math
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#define R 6440
using namespace std;

int main()
{
	int s, a;
	char tim[15];
	double deg, ans1, ans2;
	while (scanf("%d%d%s", &s, &a, tim) != EOF)
	{
		deg = a;
		if (strcmp(tim, "deg")) /* min */
			deg /= 60.0;
		deg *= acos(0.0) / 90.0;
		ans1 = (double) (s + R) * deg;
		ans2 = (double) (s + R) * sin(deg / 2) * 2;
		printf("%.6lf %.6lf\n", ans1, ans2);
	}
}