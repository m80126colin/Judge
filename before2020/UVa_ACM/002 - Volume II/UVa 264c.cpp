#include <stdio.h>
#include <math.h>
int main() {
	int n,c;
	while (scanf("%d",&n)!=EOF) {
		c=(-1.0+sqrt((double)1+8*n))/2.0;
		printf("TERM %d IS ",n);
		if (n-(c*(c+1)/2)>0) c++;
		n-=(c*(c+1)/2);
		if (c&1) printf("%d/%d\n",1-n,c+n);
		else printf("%d/%d\n",c+n,1-n);
	}
}