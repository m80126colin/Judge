#include <stdio.h>
#include <string.h>
int isvow(char ch) {
	return (ch=='a')||(ch=='e')||(ch=='i')||(ch=='o')||(ch=='u')||(ch=='y')||(ch=='A')||(ch=='E')||(ch=='I')||(ch=='O')||(ch=='U')||(ch=='Y');
}
int main() {
	char s[201];
	int seg[3],i,j,len,ox;
	while (gets(s),strcmp(s,"e/o/i")) {
		len=strlen(s);
		ox=0;
		for (i=0;i<3;i++) seg[i]=0;
		for (i=j=0;i<len;i++) {
			if (s[i]=='/') j++;
			if (ox) {
				if (!isvow(s[i])) ox=0;
			}
			else {
				if (isvow(s[i])) {
					ox=1;
					seg[j]++;
				}
			}
		}
		if (seg[0]!=5) puts("1");
		else if (seg[1]!=7) puts("2");
		else if (seg[2]!=5) puts("3");
		else puts("Y");
	}
}