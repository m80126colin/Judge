#include <stdio.h>

int a1,a2,b1,b2;

int main() {
	scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
	printf("%.2lf\n%.2f\n",(double) (b1-b2)/(a2-a1),(double) (a2*b1-a1*b2)/(a2-a1));
}