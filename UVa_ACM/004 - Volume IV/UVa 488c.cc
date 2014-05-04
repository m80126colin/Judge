#include <stdio.h>
int main() {
	int a,f,t,ctr,i,j;
	for (scanf("%d",&t);t;t--) {
		for (scanf("%d%d",&a,&f);f;f--) {
			for (i=1;i<=a;i++) {
				for (j=1;j<=i;j++) putchar(i+'0');
				puts("");
			}
			for (i=a-1;i;i--) {
				for (j=1;j<=i;j++) putchar(i+'0');
				puts("");
			}
			if (f>1) puts("");
		}
		if (t>1) puts("");
	}
}