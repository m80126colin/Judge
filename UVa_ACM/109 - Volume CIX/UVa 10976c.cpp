#include <stdio.h>
#include <string.h>
char s[100000],s2[50];
int main() {
	int k,y,ctr;
	while (scanf("%d",&k)!=EOF) {
		ctr=0;
		s[0]='\0';
		for (y=k+1;y<=2*k;y++) {
			if (k*k%(y-k)==0) ctr++,sprintf(s2,"1/%d = 1/%d + 1/%d\n",k,k*y/(y-k),y),strcat(s,s2);
		}
		printf("%d\n%s",ctr,s);
	}
}