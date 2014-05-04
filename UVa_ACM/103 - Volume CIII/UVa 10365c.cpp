#include <stdio.h>
#include <math.h>
#define MAX 2000000000
int main() {
	int a,b,c,n,nn,t,minn;
	for (scanf("%d",&t);t;t--) {
		scanf("%d",&n);
		minn = MAX;
		for (a=cbrt((double)n*n)+1;a;a--) {
			if (!(n%a)) {
				nn=n/a;
				for (b=sqrt((double)nn)+1;b;b--) {
					if (!(nn%b)) {
						c=nn/b;
						if (2*(a*b+b*c+a*c) < minn) minn=2*(a*b+b*c+a*c);
					}
				}
			}
		}
		printf("%d\n",minn);
	}
}