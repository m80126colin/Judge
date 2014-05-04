#include <stdio.h>
int main() {
	int n,i,ox;
	double x[2],y[2],hx[2],hy[2];
	while (scanf("%d",&n)!=EOF) {
		for (i=0;i<2;i++) scanf("%lf%lf",&x[i],&y[i]);
		ox=1;
		for (i=0;i<n;i++) {
			scanf("%lf%lf",&hx[0],&hy[0]);
			if (ox && 4*((x[0]-hx[0])*(x[0]-hx[0])+(y[0]-hy[0])*(y[0]-hy[0])) <= ((x[1]-hx[0])*(x[1]-hx[0])+(y[1]-hy[0])*(y[1]-hy[0]))) {
				ox=0;
				hx[1]=hx[0],hy[1]=hy[0];
			}
		}
		if (ox) puts("The gopher cannot escape.");
		else printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",hx[1],hy[1]);
	}
}