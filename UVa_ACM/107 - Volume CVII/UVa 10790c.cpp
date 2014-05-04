#include <stdio.h>
int main() {
	int a,b,t;
	for (t=1;scanf("%d%d",&a,&b)&&(a||b);t++) printf("Case %d: %lld\n",t,(long long) a*b*(a-1)*(b-1)/4);
}