#include <stdio.h>
int main() {
	int num[10000],index[10000];
	int i,j,k,n,ox;
	while (scanf("%d:",&n),n) {
		ox=1;
		for (i=0;i<n;i++) scanf("%lld",&num[i]),index[num[i]]=i;
		for (i=0;i<n-2;i++) {
			for (j=i+1;j<n-1;j++) {
				k=2*num[j]-num[i];
				if (k>=0 && k<n && index[k]>j) {
					ox=0;
					break;
				}
			}
		}
		puts((ox)?"yes":"no");
	}
}