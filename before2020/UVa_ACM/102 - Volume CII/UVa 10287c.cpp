#include <stdio.h>
#include <math.h>
#define sqrt7 sqrt((long double)7.0)
#define sqrt3 sqrt((long double)3.0)
int main() {
	long double a;
	while (scanf("%Lf",&a)!=EOF) printf("%.10Lf %.10Lf %.10Lf %.10Lf\n",a*sqrt3/2.0,a*(2*sqrt3-3.0),a*sqrt3/4.0,a*(6.0*sqrt7-7.0*sqrt3)/10.0);
}