#include <stdio.h>
typedef struct point Point;
struct point {
	int x,y;
};
int d(Point left,Point right) {
	return (left.x-right.x)*(left.x-right.x)+(left.y-right.y)*(left.y-right.y);
}
int main() {
	int n,i,j,maxv;
	Point p[3000],maxn;
	while (scanf("%d",&n),n) {
		maxn.x=maxn.y=maxv=0;
		for (i=0;i<n;i++) scanf("%d%d",&p[i].x,&p[i].y);
		for (i=0;i<n;i++) {
			for (j=i+1;j<n;j++) {
				if (d(p[i],p[j])>maxv) maxn.x=i,maxn.y=j,maxv=d(p[i],p[j]);
			}
		}
		printf("%d %d\n",maxn.x,maxn.y);
	}
}