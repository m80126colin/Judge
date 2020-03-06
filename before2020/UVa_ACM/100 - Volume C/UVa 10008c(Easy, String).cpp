/**
 *  @judge UVa
 *  @id 10008c
 *  @tag Easy, String
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef struct letter Letter;
struct letter{
	int ascii,frequency;
};
int main() {
	Letter w[26],temp;
	char s[500];
	int i,j;
	for (i=0;i<26;i++) w[i].ascii=i,w[i].frequency=0;
	while (scanf("%s",&s)!=EOF) {
		for (i=0;i<strlen(s);i++) {
			if (isalpha(s[i])) {
				if ('A'<=s[i] && s[i]<='Z') w[s[i]-'A'].frequency++;
				else w[s[i]-'a'].frequency++;
			}
		}
	}
	for (i=0;i<26;i++) {
		for (j=i+1;j<26;j++) {
			if (w[j].frequency>w[i].frequency || (w[j].frequency==w[i].frequency && w[i].ascii>w[j].ascii) ) {
				temp=w[i];
				w[i]=w[j];
				w[j]=temp;
			}
		}
	}
	for (i=0;i<26;i++) {
		if (w[i].frequency) printf("%c %d\n",w[i].ascii+'A',w[i].frequency);
		else break;
	}
}