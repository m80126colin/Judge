#include <stdio.h>
void swap(int *a,int *b) {*a^=*b;*b^=*a;*a^=*b;}
int main() {
	int a[3];
	while (scanf("%d%d%d",&a[0],&a[1],&a[2])!=EOF) {
		if (a[0] > a[1]) swap(&a[0],&a[1]);
		if (a[1] > a[2]) swap(&a[1],&a[2]);
		if (a[0] > a[1]) swap(&a[0],&a[1]);
		if (a[0]+a[1]>a[2]) puts("fit");
		else puts("unfit");
	}
}