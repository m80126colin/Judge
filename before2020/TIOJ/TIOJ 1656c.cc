#include <stdio.h>
int main() {
	int n;
	while (scanf("%d",&n)!=EOF) {
		if (n%3 || !(n%9)&&n%27) puts("happy");
		else puts("sad");
	}
}