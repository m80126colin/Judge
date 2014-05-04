#include <stdio.h>
int main() {
	int t,n,ctr,temp,i,j,a[10000];
	for (scanf("%d",&t),ctr=1;ctr<=t;ctr++) {
		scanf("%d",&n);
		a[0]=n;
		for (i=1;i<10000;i++) {
			for (temp=a[i-1],a[i]=0;temp;temp/=10) a[i]+=(temp%10)*(temp%10);
			if (a[i]==1) {
				printf("Case #%d: %d is a Happy number.\n",ctr,n);
				break;
			}
			else {
				for (j=0;j<i;j++) {
					if (a[i]==a[j]) {
						printf("Case #%d: %d is an Unhappy number.\n",ctr,n);
						break;
					}
				}
				if (j<i) break;
			}
		}
	}
}