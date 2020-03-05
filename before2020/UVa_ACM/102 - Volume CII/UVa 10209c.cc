#include <stdio.h>
#include <math.h>
int main() {
	double l;
	while (scanf("%lf",&l)!=EOF) printf("%.3lf %.3lf %.3lf\n",(3.0+2.0*acos(0.0)-3.0*sqrt(3.0))/3*l*l,(-12.0+2.0*acos(0.0)+6.0*sqrt(3.0))/3*l*l,(12.0-4.0*acos(0.0)-3.0*sqrt(3.0))/3*l*l);
}