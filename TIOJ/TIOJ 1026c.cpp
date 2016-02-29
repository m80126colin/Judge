#include <stdio.h>
int main() {
	int n,ctr;
	char ch[32];
	ctr=0;
	for (scanf("%d",&n),n>>=1;n;n>>=1) {
		ctr++;
		if (n&1) ch[ctr-1]='+';
		else ch[ctr-1]='-';
	}
	ch[ctr]='+',ch[++ctr]='\0';
	printf("%d\n%s\n",ctr,ch);
}