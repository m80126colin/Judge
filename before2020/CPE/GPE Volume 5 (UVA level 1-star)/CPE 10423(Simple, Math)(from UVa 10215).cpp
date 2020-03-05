#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

/*
let L > W
f (x) = (L - 2x)(W - 2x)x
      =  4x^3 - 2(L + W)x^2 + LWx
f'(x) = 12x^2 - 4(L + W)x   + LW = 0
x = ( (L + W) +- sqrt((L - W)^2 + LW) ) / 6.0
*/

int main()
{
	double L, W, ans1, ans2, tmp;
	while (scanf("%lf%lf", &L, &W) != EOF)
	{
		if (L < W) swap(L, W);
		tmp = (L - W) * (L - W) + L * W;
		ans1 = (L + W + sqrt(tmp)) / 6.0;
		ans2 = (L + W - sqrt(tmp)) / 6.0;
		if (ans2 > 0) printf("%.3lf", ans2);
		else printf("%.3lf", ans1);
		printf(" 0.000 %.3lf\n", W / 2.0);
	}
}