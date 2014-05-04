#include <stdio.h>
int main() {
	int n;
	while (scanf("%d",&n)!=EOF) {
		if (!(n%400) || (!(n%4) && (n%100))) puts("Bissextile Year");
		else puts("Common Year");
	}
}