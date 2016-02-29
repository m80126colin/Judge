#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ifp(char *s) {
	int i;
	for (i=0;i<=strlen(s)/2;i++) {
		if (s[i]!=s[strlen(s)-i-1]) return 1;
	}
	return 0;
}

int main() {
	long long n,t,a,b;
	int i;
	char s[33],temp[33];
	for (scanf("%lld",&n);n;n--) {
		scanf("%s",&s);
		sscanf(s,"%lld",&a);
		for (i=0;i<strlen(s);i++) temp[i]=s[strlen(s)-i-1];
		temp[strlen(s)]='\0';
		sscanf(temp,"%lld",&b);
		sprintf(s,"%lld",a+b);
		for (t=1;ifp(s);t++) {
			sscanf(s,"%lld",&a);
			for (i=0;i<strlen(s);i++) temp[i]=s[strlen(s)-i-1];
			temp[strlen(s)]='\0';
			sscanf(temp,"%lld",&b);
			sprintf(s,"%lld",a+b);
		}
		printf("%lld %s\n",t,s);
	}
}