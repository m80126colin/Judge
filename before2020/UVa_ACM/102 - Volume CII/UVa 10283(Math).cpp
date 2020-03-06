/**
 *  @judge UVa
 *  @id 10283
 *  @tag Math
 */
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

#define PI (2.0 * acos(0.0))
#define ARC(x) (x / 180.0 * PI)
#define UND_AN(x) ((x - 2) * 90.0 / x)
#define TOP_AN(x) (180.0 - 2.0 * UND_AN(x))
#define UND(x) (sin(ARC(UND_AN(x))))
#define TOP(x) (sin(ARC(TOP_AN(x))))

int main()
{
	int R, N;
	double r, I, E;
	while (scanf("%d%d", &R, &N) != EOF)
	{
		if (N < 3)
		{
			r = (double) R / N;
			I = 0.0;
		}
		else
		{
			r = R / (1.0 + 2.0 * UND(N) / TOP(N));
			I = (2.0 * N * UND(N) * UND(N) / TOP(N) - PI * (N - 2.0) / 2.0) * r * r;
		}
		E = (R * R - N * r * r) * PI - I;
		printf("%.10lf %.10lf %.10lf\n", r, I, E);
	}
}