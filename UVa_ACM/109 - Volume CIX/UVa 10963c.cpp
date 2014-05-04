#include <stdio.h>
int main() {
	int t,w,d,y1,y2,ox;
	for (scanf("%d",&t);t;t--) {
		ox=1;
		d=0;
		for (scanf("%d",&w);w;w--) {
			scanf("%d%d",&y1,&y2);
			if (!d) d=y1-y2;
			else if (d!=y1-y2) ox=0;
		}
		if (ox) printf("yes\n");
		else printf("no\n");
		if (t>1) puts("");
	}
}