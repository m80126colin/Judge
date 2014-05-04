#include <stdio.h>
int main() {
	int a;
	int b[4]={86400,3600,60,1};
	char c[4][8]={"days","hours","minutes","seconds"};
	while (scanf("%d",&a)!=EOF) {
		for (int i=0;i<4;i++){
			printf("%d %s\n", a/b[i], c[i]);
			a-=a/b[i]*b[i];
		}
	}
}