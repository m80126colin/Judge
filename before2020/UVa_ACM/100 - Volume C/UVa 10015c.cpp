#include <stdio.h>
int main() {
	int ox[32610]={0},p[3500],pr,i,j,ctr;
	ox[1]=1;
	pr=0;
	for (i=1;i<32610;i++) {
		if (!ox[i]) {
			p[pr++]=i;
			for (j=2;i*j<32610;j++) ox[i*j]=1;
		}
	}
	while (scanf("%d",&pr) && pr) {
		for (i=0;i<pr;i++) ox[i]=1;
		for (i=j=0;i<pr-1;i++) {
			for (ctr=0;;j++) {
				if (j>=pr) j%=pr;
				if (ox[j]) ctr++;
				if (ctr==p[i]) {
					ox[j]=0;
					break;
				}
			}
		}
		for (i=0;i<pr;i++) if (ox[i]) {
			printf("%d\n",i+1);
			break;
		}
	}
}