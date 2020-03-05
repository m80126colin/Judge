#include <stdio.h>
typedef struct dot Dot;
struct dot{
	char index[2];
	int x,y;
};
int cross(Dot a,Dot b,Dot c,Dot z) {
	return ((z.x-a.x)*(b.y-a.y)-(b.x-a.x)*(z.y-a.y))*((z.x-a.x)*(c.y-a.y)-(c.x-a.x)*(z.y-a.y));
}
int main() {
	char maxc[4];
	int i,j,k,m,n,ox;
	int area,maxn;
	Dot d[15];
	while (scanf("%d",&n)&&n) {
		for (i=0;i<n;i++) scanf("%s%d%d",d[i].index,&d[i].x,&d[i].y);
		maxc[3]='\0';
		maxn=-1;
		for (i=0;i<n;i++) {
			for (j=i+1;j<n;j++) {
				for (k=j+1;k<n;k++) {
					ox=1;
					for (m=0;m<n&&ox;m++) {
						if (m!=i&&m!=j&&m!=k) {
							if (cross(d[i],d[j],d[k],d[m])<=0&&cross(d[j],d[i],d[k],d[m])<=0&&cross(d[k],d[i],d[j],d[m])<=0) ox=0;
						}
					}
					if (ox) {
						area=(d[k].x-d[i].x)*(d[j].y-d[i].y)-(d[k].y-d[i].y)*(d[j].x-d[i].x);
						if (area<0) area=-area;
						if (area>maxn) {
							maxn=area;
							maxc[0]=d[i].index[0];
							maxc[1]=d[j].index[0];
							maxc[2]=d[k].index[0];
						}
					}
				}
			}
		}
		printf("%s\n",maxc);
	}
}