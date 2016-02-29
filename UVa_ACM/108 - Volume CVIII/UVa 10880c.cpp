#include <stdio.h>
int main() {
	int i,j,k,l;
	int n,c,r,ctr,fnum,current;
	static int ox[45000]={0},p[5000],pr,num[5000],factor[20000];
	ox[0]=ox[1]=1;
	pr=0;
	for (i=2;i<212;i++) {
		if (!ox[i]) {
			p[pr++]=i;
			for (j=2;i*j<45000;j++) ox[i*j]=1;
		}
	}
	for (;i<45000;i++)
		if (!ox[i]) p[pr++]=i;
	for (scanf("%d",&n),ctr=1;ctr<=n;ctr++) {
		scanf("%d%d",&c,&r);
		printf("Case #%d:",ctr);
		if (c==r) puts(" 0");
		else {
			c-=r;
			for (i=0;i<pr&&p[i]<=c;i++) {
				num[i]=0;
				while (!(c%p[i])) {
					num[i]++;
					c/=p[i];
				}
			}
			factor[0]=fnum=1;
			for (j=0;j<i;j++) {
				current=fnum;
				for (k=p[j];num[j];k*=p[j],num[j]--) {
					for (l=0;l<fnum;l++) factor[current++]=factor[l]*k;
				}
				fnum=current;
			}
			if (c>1) {
				current=fnum;
				k=c;
				for (l=0;l<fnum;l++) factor[current++]=factor[l]*k;
				fnum=current;
			}
			for (i=0;i<fnum;i++) {
				for (j=i+1;j<fnum;j++) {
					if (factor[i] > factor[j]) factor[i]^=factor[j]^=factor[i]^=factor[j];
				}
			}
			for (i=0;i<fnum;i++) {
				if (factor[i]>r) printf(" %d",factor[i]);
			}
			puts("");
		}
	}
}