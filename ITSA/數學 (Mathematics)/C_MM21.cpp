#include <stdio.h>
long long a[21];
int main() {
	int i;
	for (a[0]=1,i=1;i<21;i++) a[i] = a[i-1]*i;
	while (scanf("%d",&i)!=EOF) printf("%lld\n",a[i]);
}