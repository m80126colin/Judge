#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a,const void* b) {
	return *((int *)a) - *((int *)b);
}
int main() {
	int n,i,sum;
	static int d[1000000];
	while (scanf("%d",&n)!=EOF) {
		for (i=0;i<n;i++) scanf("%d",&d[i]);
		qsort(d,n,sizeof(int),cmp);
		sum=0;
		if (n&1) {
			for (i=0;i<n;i++) if (d[i]==d[n/2]) sum++;
			printf("%d %d 1\n",d[n/2],sum);
		}
		else {
			for (i=0;i<n;i++) if (d[i]==d[n/2]||d[i]==d[n/2-1]) sum++;
			printf("%d %d %d\n",d[n/2-1],sum,d[n/2]-d[n/2-1]+1);
		}
	}
}