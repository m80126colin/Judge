#include <stdio.h>
int c;
int ox[45000]={0},p[5000],pr;
int factor[5000],fnum,dp[5000];
int main() {
	int n,i,j;
	ox[0]=ox[1]=1;
	pr=0;
	for (i=2;i<212;i++) {
		if (!ox[i]) {
			p[pr++]=i;
			for (j=2;i*j<45000;j++) ox[i*j]=1;
		}
	}
	for (i;i<45000;i++)
		if (!ox[i]) p[pr++]=i;
	while (scanf("%d",&n),n) {
		printf("%d ",n);
		fnum=c=0;
		for (i=0;p[i]<=n && i<pr;i++) {
			factor[fnum]=0;
			if (!(n%p[i])) {
				for (;!(n%p[i]);n/=p[i]) factor[fnum]++;
				fnum++;
			}
		}
		if (n>1) {
			factor[fnum]=1;
			fnum++;
		}
		c=0;
		dp[fnum]=1;
		for (i=fnum-1;i>=0;i--) dp[i]=dp[i+1]*(2*factor[i]+1);
		for (i=0;i<fnum;i++) c+=factor[i]*dp[i+1];
		printf("%d\n",c+1);
	}
}