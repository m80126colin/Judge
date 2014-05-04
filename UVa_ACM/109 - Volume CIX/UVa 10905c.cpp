#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void swap(char l[101],char r[101]) {
	char temp[101];
	strcpy(temp,l);
	strcpy(l,r);
	strcpy(r,temp);
	return;
}
int cmp(char l[101],char r[101]) {
	char s1[201],s2[201];
	strcpy(s1,l);
	strcat(s1,r);
	strcpy(s2,r);
	strcat(s2,l);
	return strcmp(s1,s2);
}
int main() {
	int n,i,j;
	char s[50][101];
	while (scanf("%d",&n),n) {
		for (i=0;i<n;i++) scanf("%s",s[i]);
		for (i=0;i<n;i++) {
			for (j=i+1;j<n;j++) {
				if (cmp(s[i],s[j])<0) swap(s[i],s[j]);
			}
		}
		for (i=0;i<n;i++) printf("%s",s[i]);
		puts("");
	}
}