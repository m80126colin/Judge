#include <stdio.h>
#include <ctype.h>
#include <string.h>
void transform(char *ch) {
	if (strchr("`1234567890-=qwertyuiop[]\\asdfghjkl;\'zxcvbnm,./",*ch)!=NULL) *ch=*(strchr("`1234567890-=qwertyuiop[]\\asdfghjkl;\'zxcvbnm,./",*ch)-2);
	return;
}
int main() {
	char ch;
	while ((ch=getchar())!=EOF) {
		if (isgraph(ch)) transform(&ch);
		putchar(ch);
	}
}