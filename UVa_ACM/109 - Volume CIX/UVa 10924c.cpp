#include <stdio.h>
#include <string.h>
int main() {
	int value,i,ox;
	char s[21];
	while (scanf("%s",&s)!=EOF) {
		for (value=i=0;i<strlen(s);i++) {
			if ('a'<=s[i]&&s[i]<='z') value+=s[i]+1-'a';
			else if ('A'<=s[i]&&s[i]<='Z') value+=s[i]+27-'A';
		}
		ox=1;
		for (i=2;i*i<=value;i++) {
			if (value%i==0) {
				ox=0;
				break;
			}
		}
		if (ox) printf("It is a prime word.\n");
		else printf("It is not a prime word.\n");
	}
}