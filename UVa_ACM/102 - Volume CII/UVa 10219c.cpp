#include <stdio.h>
#include <math.h>
int main() {
	int n,k,i;
	double c;
	while (scanf("%d%d",&n,&k)!=EOF) {
		if (n-k < k) k=n-k;
		c=0;
		for (i=n;i>n-k;i--) c+=log10((double)i);
		for (i=k;i>1;i--) c-=log10((double)i);
		i=c+1;
		printf("%d\n",i);
	}
}