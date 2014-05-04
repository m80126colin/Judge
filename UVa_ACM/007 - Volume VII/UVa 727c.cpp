#include <stdio.h>
#include <string.h>
char token[10000];
void expression();
void get_token() {
	if (gets(token)!=NULL) return;
	else strcpy(token,"");
	return;
}
void factor() {
	if (token[0]=='(') {
		get_token();
		expression();
	}
	else printf("%s",token);
	get_token();
	return;
}
void term() {
	char buf[10000];
	factor();
	while (1) {
		if (token[0]=='*'||token[0]=='/') {
			strcpy(buf,token);
			get_token();
			factor();
			printf("%s",buf);
		}
		else break;
	}
	return;
}
void expression() {
	char buf[10000];
	term();
	while (1) {
		if (token[0]=='+'||token[0]=='-') {
			strcpy(buf,token);
			get_token();
			term();
			printf("%s",buf);
		}
		else break;
	}
	return;
}
int main() {
	int t;
	char buf;
	for (scanf("%d%c%c",&t,&buf,&buf);t;t--) {
		get_token();
		expression();
		puts("");
		if (t>1) puts("");
	}
}