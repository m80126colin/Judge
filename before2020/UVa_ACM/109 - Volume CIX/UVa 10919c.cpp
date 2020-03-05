#include <stdio.h>
int main() {
	int ox,ctr,i,j,x;
	int k,m,freddie[100];
	int c[100],r[100],circur[100][100];
	while (scanf("%d",&k)&&k) {
		scanf("%d",&m);
		for (i=0;i<k;i++) scanf("%d",&freddie[i]);
		for (i=0;i<m;i++) {
			scanf("%d%d",&c[i],&r[i]);
			for (j=0;j<c[i];j++) scanf("%d",&circur[i][j]);
		}
		ox=1;
		for (i=0;i<m;i++) {
			for (ctr=j=0;j<c[i];j++) {
				for (x=0;x<k;x++) {
					if (freddie[x]==circur[i][j]) {
						ctr++;
						break;
					}
				}
			}
			if (ctr<r[i]) {
				ox=0;
				break;
			}
		}
		puts((ox)?"yes":"no");
	}
}