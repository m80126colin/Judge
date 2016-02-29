#include <stdio.h>
#include <string.h>
int main() {
	char ch[100],t[100];
	int n,k;
	while (scanf("%d%d",&n,&k)!=EOF) {
		for (;n;n--) {
			scanf("%s",&t);
			if (n==k) strcpy(ch,t);
		}
		printf("%s\n",ch);
	}
}