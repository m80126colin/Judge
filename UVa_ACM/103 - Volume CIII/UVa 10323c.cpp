#include <stdio.h>
#include <math.h>
int main() {
	int n,i;
	long long product[14];
	for (product[0]=1,i=1;i<14;i++) product[i]=i*product[i-1];
	while (scanf("%d",&n)!=EOF) (n>=0&&8<=n&&n<14) ? printf("%lld\n",product[n]) : puts(((n>=0&&14<=n)||(n<0&&n&1)) ? "Overflow!":"Underflow!");
}