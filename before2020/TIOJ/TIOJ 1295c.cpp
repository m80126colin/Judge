#include <stdio.h>
int main() {
	int i,factor[13];
	for (factor[0]=1,i=1;i<13;i++) factor[i]=i*factor[i-1];
	while (scanf("%d",&i)!=EOF) printf("%d\n",factor[i]);
}