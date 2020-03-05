#include <stdio.h>
int gcd(int x,int y) {
	if (x%y) return gcd(y,x%y);
	else return y;
}
int main() {
	int a,b;
	while (scanf("%d%d",&a,&b)&&(a||b)) printf("%d\n",gcd(a,b));
}