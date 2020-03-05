#include <stdio.h>
int main() {
	int a,b,c,d,r;
	while (scanf("%d%d%d",&a,&b,&c)!=EOF) {
		d=r=0;
		if (a+c == 2*b) d=1;
		if (a*c==b*b && a&&b&&c) r=1;
		if (d&&r) puts("both");
		else if (d) puts("arithmetic");
		else if (r) puts("geometric");
		else puts("normal");
	}
}