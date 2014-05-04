#include <stdio.h>
int n;
char hamming[17];
void combination(int m,int h) {
	if (h==0) {
		puts(hamming);
		return;
	}
	if (m==n) return;
	combination(m+1,h);
	hamming[m]++;
	combination(m+1,h-1);
	hamming[m]--;
	return;
}
int main() {
	int t,h,i;
	for (scanf("%d",&t);t;t--) {
		scanf("%d%d",&n,&h);
		for (i=0;i<n;i++) hamming[i]='0';
		hamming[n]='\0';
		combination(0,h);
		if (t>1) puts("");
	}
}