#include <stdio.h>
int main() {
	int a;
	while (scanf("%d",&a)!=EOF) printf("%d\n",(int)((double)a/0.238+1.0));
}