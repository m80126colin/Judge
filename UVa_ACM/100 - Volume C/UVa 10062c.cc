#include <stdio.h>
#include <string.h>
int main() {
	char s[1000];
	int i,j,maxnum,ox=0;
	while (gets(s)!=NULL) {
		int ch[256]={0};
		if (ox) puts("");
		maxnum=0;
		for (i=0;i<strlen(s);i++) {
			ch[s[i]]++;
			if (ch[s[i]]>maxnum) maxnum=ch[s[i]];
		}
		for (i=1;i<=maxnum;i++) {
			for (j=256;j;j--) {
				if (ch[j-1]==i) printf("%d %d\n",j-1,ch[j-1]);
			}
		}
		ox=1;
	}
}