#include <stdio.h>
int main() {
	int order[10000],buffer,ctr,i,j;
	for (ctr=0;scanf("%d",&buffer)!=EOF;ctr++) {
		for (i=0;i<ctr;i++) {
			if (buffer<=order[i]) {
				for (j=ctr;j>i;j--) order[j]=order[j-1];
				order[i]=buffer;
				break;
			}
		}
		if (i==ctr) order[ctr]=buffer;
		printf("%d\n",((ctr+1)&1)?order[ctr/2]:(order[ctr/2]+order[ctr/2+1])/2);
	}
}