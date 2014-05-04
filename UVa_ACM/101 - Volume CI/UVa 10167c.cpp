#include <stdio.h>
#include <math.h>
int main() {
	int n,i,x,y,straw_x[100],straw_y[100],pn[2],ox;
	while(scanf("%d",&n)&&n) {
		for (i=0;i<2*n;i++) scanf("%d%d",&straw_x[i],&straw_y[i]);
		ox=1;
		for (x=-500;x<=500&&ox;x++) {
			for (y=-500;y<=500&&ox;y++) {
				for (pn[0]=pn[1]=i=0;i<2*n;i++) {
					if (x*straw_x[i]+y*straw_y[i]) pn[x*straw_x[i]+y*straw_y[i]>0]++;
					else break;
				}
				if (i==2*n && pn[0]==pn[1]) printf("%d %d\n",x,y),ox=0;
			}
		}
	}
}