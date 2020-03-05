#include <stdio.h>
#include <string.h>
int main() {
	int i,len;
	char s[1001],ch;
	while (scanf("%s%c",s,&ch)!=EOF) {
		len=strlen(s);
		for (i=0;i<len;i++) putchar(s[len-i-1]);
		putchar(ch);
	}
}