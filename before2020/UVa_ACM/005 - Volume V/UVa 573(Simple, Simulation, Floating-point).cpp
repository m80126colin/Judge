/**
 *  @judge UVa
 *  @id 573
 *  @tag Simple, Simulation, Floating point
 */
#include <stdio.h>
#include <iostream>
using namespace std;

#define EPS 5.14e-7
int h, u, d, f, D;
double H;

int main()
{
	while (scanf("%d%d%d%d", &h, &u, &d, &f), (h || u || d || f))
	{
		H = 0.0;
		for (D = 0; H > -EPS && H < (double) h + EPS; D++)
		{
			if (f * D < 100) H += (double) (100 - f * D) / 100 * u;
			if (H < h + EPS) H -= d;
		}
		if (H > h - EPS)
			printf("success on day %d\n", D);
		else printf("failure on day %d\n", D);
	}
}