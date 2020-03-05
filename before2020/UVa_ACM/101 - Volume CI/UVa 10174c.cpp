#include <stdio.h>
int main() {
	char ch;
	int a,b,x,y,ox;
	while (scanf("%d%c",&a,&ch)!=EOF) {
		ox=0;
		if (ch=='\n') {
			if (a<0) ox=1,a=-a;
			if (a&1 || a%4==0) {
				if (a&1) {
					x=a/2+1;
					y=x-1;
				}
				else if (a%4==0) {
					x=a/4+1;
					y=x-2;
				}
				if (ox) x^=y^=x^=y;
				printf("%d %d\n",x,y);
			}
			else printf("Bachelor Number.\n");
		}
		else {
			scanf("%d",&b);
			while (a%2 || !(a%4)) a++;
			while (b%2 || !(b%4)) b--;
			printf("%d\n",(b-a)/4+1);
		}
	}
}