#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	int oxm,oxn,i,j,one[10][5];
	char m[102],n[102];
	for (i=0;i<10;i++) {
		one[i][0]=1;
		for (j=1;j<5;j++) one[i][j]=(one[i][j-1]*i)%10;
		one[i][0]=one[i][4];
	}
	while (scanf("%s%s",m,n)) {
		oxm=strcmp(m,"0");
		oxn=strcmp(n,"0");
		if (!oxm&&!oxn) break;
		if (oxm&&oxn) {
			oxm = m[strlen(m)-1]-'0';
			if (strlen(n)<2) oxn=atoi(n);
			else oxn=atoi(n+strlen(n)-2);
			oxn%=4;
			printf("%d\n",one[oxm][oxn]);
		}
		else if (oxm) puts("1");
		else puts("0");
	}
}