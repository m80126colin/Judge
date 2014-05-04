#include <stdio.h>
int main() {
	int n, k;
	while (scanf("%d%d",&n,&k) != EOF) puts( ((k && n % k) || (!k && n))? "Impossib1e!": "Ok!");
}