#include <stdio.h>
int main() {
	char ch[100][101];
	int map[102][102],n,m,i,j,t;
	for (t=1;scanf("%d%d",&n,&m)&&(n||m);t++) {
		for (i=0;i<n;i++) scanf("%s",ch[i]);
		for (i=0;i<=n+1;i++) 
			for (j=0;j<=m+1;j++) map[i][j]=0;
		for (i=0;i<n;i++) 
			for (j=0;j<m;j++) 
				if (ch[i][j]=='*') {
					map[i][j]++;
					map[i+1][j]++;
					map[i+2][j]++;
					map[i][j+1]++;
					map[i+2][j+1]++;
					map[i][j+2]++;
					map[i+1][j+2]++;
					map[i+2][j+2]++;
				}
		if (t>1) puts("");
		printf("Field #%d:\n",t);
		for (i=1;i<=n;i++) {
			for (j=1;j<=m;j++) {
				if (ch[i-1][j-1]=='*') putchar('*');
				else putchar(map[i][j]+'0');
			}
			puts("");
		}
	}
}