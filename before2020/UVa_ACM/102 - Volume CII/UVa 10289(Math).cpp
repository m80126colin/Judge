/**
 *  @judge UVa
 *  @id 10289
 *  @tag Math
 */
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

// let the side of square is x, and the side of equilateral triangle is r
#define PI (2.0 * acos(0.0))
// relations:
#define A1(x) (1.03527618041008 * x)
// r = (sqrt(3.0) - 1) * sqrt(2.0) * x
#define A2(x) (0.81649658092773 * x)
// r = sqrt(6.0) / 3.0 * x
#define A3(x) (0.67640791490305 * x)
// r = 2.0 * sqrt(6.0) * (sqrt(2.0) - 1) / 3.0 * x
#define A4(x) (0.63397459621556 * x)
// r = (2.0 / (2.0 + 2.0 * sqrt(3.0) / 3.0)) * x
#define A5(x) (0.554579157314857 * x)
// solve (21.0 + 8.0 * sqrt(3.0)) * r * r - (22.0 + 14.0 * sqrt(3.0)) * x * r + (8.0 + 4.0 * sqrt(3.0)) * x * x = 0
#define A6(x) (0.52578342306321 * x)
// r = (sqrt(3.0) + 1.0) / (3.0 * sqrt(3.0)) * x
#define A7(x) (0.47662710943897 * x)
// r = (sqrt(3.0) + 1.0) / (sqrt(3.0) + 4.0) * x

int main()
{
	double x;
	while (scanf("%lf", &x) != EOF)
		printf("%.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf\n", A1(x), A2(x), A3(x), A4(x), A5(x), A6(x), A7(x));
}