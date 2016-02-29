#include <stdio.h>
int main() {
	int t,d,i,j,entry;
	for (scanf("%d",&t);t;t--) {
		scanf("%d%d",&d,&i);
		entry=1;
		for (j=1;j<d;j++) {
			entry<<=1;
			if (i&1) i=(i>>1)+1;
			else {
				i>>=1;
				entry++;
			}
		}
		printf("%d\n",entry);
	}
}