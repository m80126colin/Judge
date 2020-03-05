#include <stdio.h>
int main() {
	int n,t,i;
	double a0,an,c[3000],ans;
	for (scanf("%d",&t);t;t--) {
		scanf("%d%lf%lf",&n,&a0,&an);
		for (i=0;i<n;i++) scanf("%lf",&c[i]);
		ans=an + n*a0;
		for (i=0;i<n;i++) ans-=2*(n-i)*c[i];
		ans/=(n+1);
		printf("%.2lf\n",ans);
		if (t>1) puts("");
	}
}