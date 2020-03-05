#include <stdio.h>
int num(int a,int b) {
	if (a*b==0) return 0;
	return a/b+num(b,a%b);
}
int main() {
	int a,b;
	while (scanf("%d%d",&a,&b)!=EOF) printf("%d\n",num(a,b));
}