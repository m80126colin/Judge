#include <stdio.h>
#include <ctype.h>
int main() {
	char ch;
	static int t,n,m,i,j,sum,map[502][502];
	for (scanf("%d",&t);t;t--) {
		sum=0;
		scanf("%d%d",&n,&m);
		for (i=0;i<n+2;i++) map[i][0]=map[i][m+1]=0;
		for (j=0;j<m+2;j++) map[0][j]=map[n+1][j]=0;
		for (i=0;i<n;i++)
			for (j=0;j<m;j++) {
				scanf("%c",&ch);
				if (!isdigit(ch)) j--;
				else map[i+1][j+1]=ch-'0';
			}
		for (i=1;i<=n;i++)
			for (j=1;j<=m;j++)
				if (map[i][j]) sum+=!map[i-1][j]+!map[i+1][j]+!map[i][j-1]+!map[i][j+1];
		printf("%d\n",sum);
	}
}