#include <stdio.h>
int main() {
	int a,b,c;
	while (scanf("%d%d%d",&a,&b,&c)!=EOF) {
		if (a+b==c || a+c==b || b+c==a) puts("Good Pair");
		else puts("Not Good Pair");
	}
}