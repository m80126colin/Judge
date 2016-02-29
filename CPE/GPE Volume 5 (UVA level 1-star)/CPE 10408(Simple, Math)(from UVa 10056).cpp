#include <stdio.h>
#include <math.h>
int main() {
	int s,n,i;
	double p;
	for (scanf("%d",&s);s;s--) {
		scanf("%d%lf%d",&n,&p,&i);
		if (p) printf("%.4lf\n", p*pow(1-p,i-1)/(1.0-pow(1-p,n)) );
		else puts("0.0000");
	}
}