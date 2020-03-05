#include <stdio.h>
int main() {
	int a,b,t,i;
	for (scanf("%d",&t),i=1;i<=t;i++) {
		scanf("%d%d",&a,&b);
		if (!(a&1)) a++;
		if (!(b&1)) b--;
		printf("Case %d: %d\n",i,(a+b)*(b-a+2)/4);
	}
}