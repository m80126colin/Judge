#include <stdio.h>
int min(int a,int b) {
	if (a<b) return a;
	return b;
}
int main() {
	int a,b,d,a1[32],b1[32];
	while (scanf("%d%d",&a,&b)!=EOF) {
		for (d=0;a;d++,a>>=1) a1[d]=a&1;
		a=d;
		for (d=0;b;d++,b>>=1) b1[d]=b&1;
		b=d;
		for (d=0;d<min(a,b);d++) {
			if (a1[a-1-d]!=b1[b-1-d]) break;
		}
		printf("%d\n",a-d+b-d);
	}
}