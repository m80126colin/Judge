#include <stdio.h>
#include <string.h>
int main() {
	int t,ctr,i,j,ox;
	int prime[2001],ascii[128];
	char s[2001];
	for (i=0;i<=2000;i++) prime[i]=1;
	prime[0]=prime[1]=0;
	for (i=2;i<50;i++) {
		if (prime[i]) {
			for (j=2;i*j<=2000;j++) prime[i*j]=0;
		}
	}
	for (scanf("%d",&t),ctr=1;ctr<=t;ctr++) {
		ox=0;
		scanf("%s",&s);
		for (i=0;i<128;i++) ascii[i]=0;
		for (i=0;i<strlen(s);i++) ascii[s[i]]++;
		printf("Case %d: ",ctr);
		for (i=0;i<128;i++) if (prime[ascii[i]]) putchar(i),ox=1;
		if (!ox) puts("empty");
		else puts("");
	}
}