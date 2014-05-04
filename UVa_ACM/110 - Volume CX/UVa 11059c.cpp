#include <stdio.h>
int main() {
	long long t,n,i,j,s[18],temp,maxnum;
	for (t=1;scanf("%lld",&n)!=EOF;t++) {
		maxnum=0;
		for (i=0;i<n;i++) scanf("%lld",&s[i]);
		for (i=0;i<n;i++) {
			temp=1;
			for (j=i;j<n;j++) {
				temp*=s[j];
				if (maxnum<temp) maxnum=temp;
			}
		}
		printf("Case #%lld: The maximum product is %lld.\n\n",t,maxnum);
	}
}