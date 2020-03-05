#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int max(int i,int j) {
	if (i>j) return i;
	return j;
}
int main() {
	int i,j,map[100][100],dp[100][100],t,n,m,entry;
	char s[500],*sptr;
	for (scanf("%d",&t);t;t--) {
		scanf("%d%d",&n,&m);
		for (i=0;i<=n;i++) {
			for (j=0;j<=m;j++)
				map[i][j]=1,dp[i][j]=0;
		}
		gets(s);
		for (i=0;i<n;i++) {
			gets(s);
			sptr = strtok(s," ");
			entry = atoi(s);
			sptr = strtok(NULL," ");
			while (sptr != NULL) {
				j = atoi(sptr);
				map[entry][j]=0;
				sptr = strtok(NULL," ");
			}
		}
		dp[1][1]=1;
		for (i=1;i<=n;i++) {
			for (j=1;j<=m;j++) {
				if (map[i][j]) dp[i][j]=max(dp[i][j],dp[i-1][j]+dp[i][j-1]);
				else dp[i][j]=0;
			}
		}
		printf("%d\n",dp[n][m]);
		if (t>1) puts("");
	}
}