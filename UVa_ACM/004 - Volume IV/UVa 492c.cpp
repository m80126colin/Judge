#include <stdio.h>
#include <ctype.h>
#include <string.h>
int isvow(char ch) {
	return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U';
}
int main() {
	int vow,word;
	char ch,temp;
	vow=word=0;
	while ((ch=getchar())!=EOF) {
		if (isalpha(ch)) {
			if (!word) {
				word=1;
				if (isvow(ch)) vow=1,putchar(ch);
				else vow=0,temp=ch;
			}
			else putchar(ch);
		}
		else {
			if (word) {
				if (!vow) putchar(temp);
				putchar('a');
				putchar('y');
			}
			putchar(ch);
			word=0;
		}
	}
}