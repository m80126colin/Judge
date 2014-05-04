#include <stdio.h>
int main() {
	int n,a,i,m;
	double x,y;
	while (scanf("%d%d",&n,&a),n||a) {
		m=0;
		for (i=0;i<n;i++) {
			scanf("%lf%lf",&x,&y);
			if (x*x+y*y<a*a&&(x-a)*(x-a)+y*y<a*a&&x*x+(y-a)*(y-a)<a*a&&(x-a)*(x-a)+(y-a)*(y-a)<a*a) m++;
		}
		printf("%.5lf\n",(double)m/n*a*a);
	}
}