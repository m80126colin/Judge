#include <stdio.h>
int main() {
	int n,i;
	while (scanf("%d",&n)!=EOF) {
		for (i = 1; i <= n; i++) printf("%d*%d=%d\n",i,i,i*i);
	}
}