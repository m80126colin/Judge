#include <stdio.h>
int main() {
	int n,i,ox;
	while (scanf("%d",&n)!=EOF) {
		n/=35;
		ox=0;
		for (i=1;i<=n;i++) {
			if (ox) putchar(' ');
			printf("%d",i*35);
			ox=1;
		}
		puts("");
	}
}