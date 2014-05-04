#include <stdio.h>
int main() {
	int a,b,c,d;
	while (scanf("%d%d%d%d",&a,&b,&c,&d),a||b||c||d) printf("%d\n",1080+((a-b+(a-b<0)*40)+(c-b+(c-b<0)*40)+(c-d+(c-d<0)*40))*9);
}