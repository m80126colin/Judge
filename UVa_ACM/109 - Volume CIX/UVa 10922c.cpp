#include <stdio.h>
#include <string.h>
int main() {
	char s[1001];
	int n,d,i,len;
	while (scanf("%s",s)&&strcmp(s,"0")) {
		d=n=0;
		len=strlen(s);
		for (i=0;i<len;i++) n+=s[i]-'0';
		while (!(n%9)) {
			d++;
			if (n==9) break;
			for (len=0;n;n/=10) len+=n%10;
			n=len;
		}
		if (d) printf("%s is a multiple of 9 and has 9-degree %d.\n",s,d);
		else printf("%s is not a multiple of 9.\n",s);
	}
}