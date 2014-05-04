#include <stdio.h>
#include <string.h>
#include <math.h>
int n,len;
char s[1000001];
int find_sublen(int sublen) {
	int i,j,k;
	if (len%sublen) return 0;
	for (j=sublen;j<len;j+=sublen) {
		for (k=0;k<sublen;k++) {
			if (s[k]!=s[j+k]) return 0;
		}
	}
	return sublen;
}
int main() {
	int i,sublen,ox;
	while (scanf("%s",s)&&strcmp(s,".")) {
		len=strlen(s);
		n=sqrt((double) strlen(s));
		ox=1;
		for (i=1;i<=n;i++) {
			if (sublen=find_sublen(i)) {
				ox=0;
				printf("%d\n",len/sublen);
				break;
			}
		}
		if (ox) {
			for (i=n;i;i--) {
				if (sublen=find_sublen(len/i)) {
					ox=0;
					printf("%d\n",len/sublen);
					break;
				}
			}
		}
	}
}