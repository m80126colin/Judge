#include <stdio.h>
int t,n,m,x[50],kai[50],sum[50],out;
void recur(int i,int s) {
	int j,k,ox;
	if (s==t) {
		ox=0;
		for (j=1;j<=m;j++) {
			for (k=1;k<=sum[j];k++) {
				if (ox) putchar('+');
				printf("%d",x[j]);
				ox=1;
			}
		}
		out=0;
		puts("");
		return;
	}
	if (i>m) return;
	for (j=kai[i];j>=0;j--) {
		if (s+j*x[i]<=t) {
			sum[i]=j;
			recur(i+1,s+j*x[i]);
		}
	}
	return;
}
int main() {
	int i,entry;
	while (scanf("%d%d",&t,&n),n) {
		for (i=0;i<=n;i++) x[i]=kai[i]=0;
		for (i=m=0;i<n;i++) {
			scanf("%d",&entry);
			if (entry!=x[m]) x[++m]=entry;
			kai[m]++;
		}
		out=1;
		printf("Sums of %d:\n",t);
		recur(1,0);
		if (out) puts("NONE");
	}
}