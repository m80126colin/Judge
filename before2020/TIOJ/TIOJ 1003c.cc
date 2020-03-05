#include <stdio.h>
int main() {
	int a;
	while (scanf("%d",&a)!=EOF) printf("%d\n",a*(a+1)/2+1);
}