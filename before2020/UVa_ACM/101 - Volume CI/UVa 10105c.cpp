#include <stdio.h>
int c(int n,int m) {
	int sum=1,i,j;
	for (i=n,j=m;i>n-m;i--) {
		for (sum*=i;j>1 && sum/j==0;j--) sum/=j;
	}
	while (j>1) sum/=j,j--;
	return sum;
}
int main() {
	int n,k,w[13],i,j,p,sum;
	while (scanf("%d%d",&n,&k)!=EOF) {
		for (i=p=0;i<k;i++) {
			scanf("%d",&j);
			if (j) w[p++]=j;
		}
		sum=1;
		for (i=0;i<p;i++) {
			sum*=c(n,w[i]);
			n-=w[i];
		}
		printf("%d\n",sum);
	}
}