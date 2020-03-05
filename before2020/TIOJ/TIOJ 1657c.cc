#include <stdio.h>
int main() {
	int a,b,i,j;
	while (scanf("%d%d",&a,&b)!=EOF) {
		for (i=1;i<=a;i++) {
			for (j=1;j<=b;j++) {
				printf("%d*%d=%d",i,j,i*j);
				if (j<b) printf(" ");
			}
			puts("");
		}
	}
}