#include <stdio.h>
int main() {
	int a;
	while (scanf("%d", &a)!=EOF) printf("NT10=%d\nNT5=%d\nNT1=%d\n",a/10,a%10/5,a%5);
}