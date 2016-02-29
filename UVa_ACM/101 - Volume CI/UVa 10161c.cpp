#include <stdio.h>
#include <math.h>
int main() {
	int n,m;
	while (scanf("%d",&n)&&n) {
		m=sqrt((double)n-1);
		if (m&1) {
			if (n-m*m > m+1) printf("%d %d\n",m+1,2*(m+1)-n+m*m);
			else printf("%d %d\n",n-m*m,m+1);
		}
		else {
			if (n-m*m > m+1) printf("%d %d\n",2*(m+1)-n+m*m,m+1);
			else printf("%d %d\n",m+1,n-m*m);
		}
	}
}