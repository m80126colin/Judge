#include <stdio.h>
#include <string.h>

int main() {
	int i,n;
	char s[10], day[7][10]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	while (scanf("%s%d",s,&n)!=EOF) {
		for (i=0;i<7;i++) if (strcmp(s,day[i])==0) break;
		printf("%s\n",day[(i+n)%7]);
	}
}