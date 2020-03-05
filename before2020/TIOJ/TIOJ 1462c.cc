#include <stdio.h>
struct point {
	int x,y;
};

int main() {
	point p,b,bv;
	int n,t,i,ox;
	while (scanf("%d%d%d%d",&n,&t,&p.x,&p.y),(n||t||p.x||p.y)) {
		ox=0;
		for (i=1;i<=n;i++) {
			scanf("%d%d%d%d",&b.x,&b.y,&bv.x,&bv.y);
			if ( (p.x-b.x)*bv.y==(p.y-b.y)*bv.x) {
				if (bv.x&&(double)(p.x-b.x)/bv.x>0&&(double)(p.x-b.x)/bv.x<=t) ox=1;
				else if (bv.y&&(double)(p.y-b.y)/bv.y>0&&(double)(p.y-b.y)/bv.y<=t) ox=1;
			}
		}
		if (ox) puts("true");
		else puts("false");
	}
}