#include <stdio.h>
#include <math.h>
#define pi acos((long double)-1.0)
int main() {
	long double a;
	while (scanf("%Lf",&a)!=EOF) printf("%.10Lf\n",a*sin((long double)0.6*pi)/sin((long double)0.35*pi));
}