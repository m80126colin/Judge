#include <stdio.h>
int main() {
	int p[100],i,j,n,k,ctr,step,record;
	while (scanf("%d%d",&n,&k)&&(n||k)) {
		for (i=0;i<n;i++) p[i]=i+1;
		ctr=n,step=0;
		for (i=j=0;ctr>1;i++) {
			if (i>=n) i%=n;
			if (p[i]) j++;
			if (j==k) {
				j=0;
				step++;
				if (step&1) p[i]=0,record=i,ctr--;
				else p[record]=p[i],p[i]=0,i=record;
			}
		}
		for (i=0;i<n;i++) {
			if (p[i]) {
				printf("%d\n",(p[i]==1)?1:2-p[i]+n);
				break;
			}
		}
	}
}