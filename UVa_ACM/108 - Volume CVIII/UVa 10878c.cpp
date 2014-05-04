#include <stdio.h>
#include <string.h>
int main() {
	int value,i,j;
	char s[12],t[12];
	gets(t);
	while (gets(s),strcmp(s,t)) {
		for (i=9,j=1,value=0;i;i--) {
			if (s[i]=='o') value+=j;
			if (s[i]!='.') j<<=1;
		}
		printf("%c",value);
	}
}