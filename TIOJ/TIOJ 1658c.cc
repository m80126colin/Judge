#include <stdio.h>
int main() {
	int n,b,i,j;
	while (scanf("%d%d",&n,&b)!=EOF) {
		for (i=1;i<=n;i++) {
			for (j=1;j<=n-i;j++) putchar(' ');
			putchar('*');
			if (i>1) {
				if (b||i==n) for (j=2*(i-1)-1;j;j--) putchar('*');
				else for (j=2*(i-1)-1;j;j--) putchar(' ');
				puts("*");
			}
			else puts("");
		}
	}
}