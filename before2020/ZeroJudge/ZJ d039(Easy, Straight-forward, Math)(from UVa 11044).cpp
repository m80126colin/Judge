#include <stdio.h>

int main() {
	int t,i,j;
	scanf("%d\n",&t);
	while (t--) {
		scanf("%d %d",&i,&j);
		printf("%d\n",(i/3)*(j/3));
	}
}