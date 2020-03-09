/**
 *  @judge CPE
 *  @id 10554
 *  @source UVa 10195
 * 
 *  @tag Simple, Math, Geometry
 */
#include <stdio.h>
#include <math.h>
#include <iostream>
#define EPS 5.14e-7
using namespace std;

int main()
{
	double a, b, c, s;
	while (scanf("%lf%lf%lf", &a, &b, &c) != EOF)
	{
		printf("The radius of the round table is: ");
		if (a > EPS || b > EPS || c > EPS) // not zero
		{
			s = (a + b + c) / 2.0;
			printf("%.3lf\n", 2.0 * sqrt(s * (s - a) * (s - b) * (s - c)) / (a + b + c));
		}
		else puts("0.000");
	}
}