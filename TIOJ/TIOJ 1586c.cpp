#include <stdio.h>

char s[21]=", happy new year!!!\n";

int main() {
	int n,i;
	char ch;
	for (scanf("%d",&n),ch=getchar();n;n--) {
		while (ch=getchar(),ch!='\n') putchar(ch);
		for (i=0;i<20;i++) putchar(s[i]);
	}
}