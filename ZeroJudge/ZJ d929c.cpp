#include <stdio.h>
#include <string.h>
int main() {
	char s[101];
	int i,t,len,ox;
	for (scanf("%d",&t);t;t--) {
		scanf("%s",s);
		ox=1;
		for (len=strlen(s),i=0;i<len/2;i++) 
			if (s[i]!=s[len-1-i]) ox=0,i=len;
		puts((ox) ? "yes" : "no");
	}
}