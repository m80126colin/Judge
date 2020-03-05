#include <stdio.h>
#include <string.h>
int main() {
	int t,ctr,i,j,len,ox;
	char ch,s[2010],*sptr,*sptr2;
	char code[54][7]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",
		".--","-..-","-.--","--..","-----",".----","..---","...--","....-",".....","-....","--...","---..","----.",".-.-.-","--..--","..--..",".----.",
		"-.-.--","-..-.","-.--.","-.--.-",".-...","---...","-.-.-.","-...-",".-.-.","-....-","..--.-",".-..-.",".--.-."};
	char geass[54]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,?\'!/()&:;=+-_\"@"};
	len=strlen(geass);
	for (scanf("%d%c",&t,&ch),ctr=1;ctr<=t;ctr++) {
		gets(s);
		if (ctr>1) puts("");
		printf("Message #%d\n",ctr);
		ox=0;
		sptr=s;
		while ((sptr2=strchr(sptr,' '))!=NULL) {
			*sptr2='\0';
			for (i=0;i<len;i++) if (!strcmp(sptr,code[i])) putchar(geass[i]);
			if (*(sptr2+1)==' ') putchar(32),sptr=sptr2+2;
			else sptr=sptr2+1;
		}
		for (i=0;i<len;i++) if (!strcmp(sptr,code[i])) putchar(geass[i]);
		puts("");
	}
}