#include <stdio.h>
#include <math.h>
int main() {
	double n,r,pi=acos(-1.0);
	while (scanf("%lf%lf",&r,&n)!=EOF) printf("%.3lf\n",0.5*n*pow(r,2.0)*sin(2.0*pi/n));
}