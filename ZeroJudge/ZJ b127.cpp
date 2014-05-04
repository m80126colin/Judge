#include <stdio.h>

int main() {
	int n[46];
	n[1]=1;n[2]=2;
	for (n[0]=3;n[0]<=45;n[0]++) n[n[0]]=n[n[0]-1]+n[n[0]-2];
	while (scanf("%d",&n[0])!=EOF) printf("%d\n",n[n[0]]);
}