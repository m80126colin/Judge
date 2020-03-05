#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	char s[50],ch;
	int z,ctr,p,t,i,j,k,ox,map[101][101];
	for (scanf("%d",&z);z;z--) {
		scanf("%d%d",&p,&t);
		for (i=0;i<=p;i++) {
			map[i][0]=i;
			for (j=1;j<=t;j++) map[i][j]=0;
		}
		scanf("%c",&ch);
		while (gets(s)!=NULL) {
			if (strcmp(s,"")) {
				for (i=0;i<strlen(s)&&s[i]!=' ';i++) ;
				s[i]='\0';
				j=atoi(s+i+1);
				i=atoi(s);
				map[i][j]=1;
			}
			else break;
		}
		ctr=p;
		for (i=1;i<=p;i++) {
			for (j=1;j<=p;j++) {
				if (map[i][0]!=map[j][0]) {
					ox=1;
					for (k=1;k<=t;k++) {
						if (map[i][k]!=map[j][k]) {
							ox=0;
							break;
						}
					}
					if (ox) {
						ctr--;
						ox=map[j][0];
						for (k=1;k<=p;k++) {
							if (map[k][0]==ox) map[k][0]=map[i][0];
						}
					}
				}
			}
		}
		printf("%d\n",ctr);
		if (z>1) puts("");
	}
}