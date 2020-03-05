#include <stdio.h>
#include <string.h>
typedef struct people People;
struct people{
	int w,l;
};
int main() {
	int n,k,i,p1,p2,ox;
	People p[101];
	char m1[20],m2[20];
	ox=0;
	while (scanf("%d",&n),n) {
		if (ox) puts("");
		scanf("%d",&k);
		for (i=1;i<=n;i++) p[i].w=p[i].l=0;
		for (i=1;i<=k*n*(n-1)/2;i++) {
			scanf("%d%s%d%s",&p1,&m1,&p2,&m2);
			if (strcmp(m1,"rock")==0) {
				if (strcmp(m2,"scissors")==0) p[p1].w++,p[p2].l++;
				else if (strcmp(m2,"paper")==0) p[p1].l++,p[p2].w++;
			}
			else if (strcmp(m1,"scissors")==0) {
				if (strcmp(m2,"paper")==0) p[p1].w++,p[p2].l++;
				else if (strcmp(m2,"rock")==0) p[p1].l++,p[p2].w++;
			}
			else if (strcmp(m1,"paper")==0) {
				if (strcmp(m2,"rock")==0) p[p1].w++,p[p2].l++;
				else if (strcmp(m2,"scissors")==0) p[p1].l++,p[p2].w++;
			}
		}
		for (i=1;i<=n;i++) {
			if (p[i].w==0&&p[i].l==0) puts("-");
			else printf("%.3lf\n",(double)p[i].w/(p[i].w+p[i].l));
		}
		ox=1;
	}
}