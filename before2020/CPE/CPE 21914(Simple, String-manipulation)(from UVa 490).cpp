/**
 *  @judge CPE
 *  @id 21914
 *  @tag Simple, String Manipulation
 */
#include <stdio.h>
#include <string.h>
int main() {
	int n,i,j,len[101],mlen;
	char s[101][101];
	mlen=0;
	for (n=0,i=0;(s[n][i]=getchar())!=EOF;i++) {
		if (s[n][i]=='\t') i--;
		if (s[n][i]=='\n') {
			s[n][i]=' ';
			s[n][i+1]='\0';
			len[n]=strlen(s[n]);
			if (len[n]>mlen) mlen=len[n];
			n++;
			i=-1;
		}
	}
	for (j=0;j<mlen-1;j++) {
		for (i=n-1;i>=0;i--) {
			if (j<len[i]) putchar(s[i][j]);
			else putchar(' ');
		}
		puts("");
	}
}