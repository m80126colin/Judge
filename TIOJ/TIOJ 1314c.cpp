#include <stdio.h>
int main() {
	int a,b,c,n;
	for (scanf("%d",&n);n;n--) {
		scanf("%d%d%d",&a,&b,&c);
		if (a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a) puts("yes");
		else puts("no");
	}
}