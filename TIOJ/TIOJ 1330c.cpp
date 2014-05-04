#include <stdio.h>
int main() {
	int n,i;
	for (scanf("%d",&n);n;n--) scanf("%d",&i),printf("%d\n",i&1);
}