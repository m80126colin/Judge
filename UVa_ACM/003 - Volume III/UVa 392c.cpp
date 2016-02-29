#include <stdio.h>
int input(int poly[9]) {
	int i;
	for (i=8;i>=0;i--) if (scanf("%d",&poly[i])==EOF) return 0;
	return 1;
}
int main() {
	int poly[9],i,ox;
	while (input(poly)) {
		ox=0;
		for (i=8;i>=0;i--) {
			if (poly[i]) {
				if (ox) {
					if (poly[i]<0) {
						printf(" - ");
						poly[i]=-poly[i];
					}
					else printf(" + ");
					if (i&&poly[i]!=1 || i==0) printf("%d",poly[i]);
					if (i) printf("x");
					if (i>1) printf("^%d",i);
				}
				else {
					ox=1;
					if (poly[i]<0) {
						printf("-");
						poly[i]=-poly[i];
					}
					if (i&&poly[i]!=1 || i==0) printf("%d",poly[i]);
					if (i) printf("x");
					if (i>1) printf("^%d",i);
				}
			}
		}
		if (!ox) printf("0");
		puts("");
	}
}