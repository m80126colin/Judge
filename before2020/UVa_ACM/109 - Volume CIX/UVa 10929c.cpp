#include <stdio.h>
#include <string.h>
int main() {
	int odd,even,i;
	char s[1001];
	while (scanf("%s",&s),strcmp(s,"0")) {
		for (odd=even=i=0;i<strlen(s);i++) {
			if (i&1) odd+=s[i]-'0';
			else even+=s[i]-'0';
		}
		if ((odd-even)%11==0) printf("%s is a multiple of 11.\n",s);
		else printf("%s is not a multiple of 11.\n",s);
	}
}