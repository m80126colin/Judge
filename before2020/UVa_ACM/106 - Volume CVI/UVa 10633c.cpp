#include <stdio.h>
int main() {
	int ox;
	long long n,i;
	while (scanf("%lld",&n),n) {
		ox=0;
		for (i=9;i>=0;i--) {
			if (!((n-i)%9)) {
				if (ox) putchar(' ');
				printf("%lld",(n-i)/9*10+i);
				ox=1;
			}
		}
		puts("");
	}
}