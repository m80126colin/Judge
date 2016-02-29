#include <stdio.h>
#include <string.h>
int main() {
	char s[1001];
	int i,j,aa,bb,len,a[1001],b[1001],t;
	for (t=1;gets(s)!=NULL;t++) {
		len=strlen(s);
		aa=bb=a[0]=b[0]=0;
		for (i=1;i<=len;i++) {
			(s[i-1]=='a') ? aa++ : bb++;
			a[i]=aa;
			b[i]=bb;
		}
		if (t>1) puts("");
		printf("AB Circle #%d:\n",t);
		for (i=0;i<len;i++) {
			for (j=i+1;j<len;j++) {
				if (a[j]-a[i] == b[len]+b[i]-b[j] || b[j]-b[i] == a[len]+a[i]-a[j]) printf("%d,%d\n",i,j);
			}
		}
	}
}