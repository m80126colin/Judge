#include <stdio.h>
struct ans{
	int t,w,g;
};
int main() {
	int i,ttl;
	int m,n,wa[101],ac[101];
	ans a;
	while (scanf("%d%d",&m,&n)&&(m||n)) {
		ttl=ac[0]=0;
		for (i=1;i<=m;i++) wa[i]=ac[i]=0;
		for (i=1;i<=n;i++) {
			scanf("%d%d%d",&a.t,&a.w,&a.g);
			if (!ac[a.w]) {
				if (a.g) {
					ac[a.w]=1;
					ac[0]++;
					ttl+=a.t+wa[a.w]*20;
				}
				else wa[a.w]++;
			}
		}
		printf("%d %d\n",ttl,ac[0]);
	}
}