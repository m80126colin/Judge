#include <stdio.h>
int main() {
	int t,n,i,j,factor[13];
	factor[0]=1;
	for (i=1;i<13;i++) factor[i]=i*factor[i-1];
	for (scanf("%d",&t),i=1;i<=t;i++) {
		printf("Case #%d:\n",i);
		for (scanf("%d",&n),j=0;j<=n;j++) printf("TFCIS%d=%d\n",j,factor[j]);
	}
}