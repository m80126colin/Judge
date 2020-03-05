#include <stdio.h>
#include <math.h>

#define PI acos(-1.0)
#define EPS 5.14e-7

int t;
double a, b, ans;

int main()
{
	for (scanf("%d", &t); t; t--)
	{
		scanf("%lf%lf", &a, &b);
		ans = atan2(a, b);
		if (ans < -EPS) ans += 2.0 * PI;
		printf("%.2lf %.2lf\n", ans, sqrt(a * a + b * b));
	}
}