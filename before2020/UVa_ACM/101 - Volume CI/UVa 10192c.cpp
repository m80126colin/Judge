#include <stdio.h>
#include <string.h>
inline int max(int i,int j) {
	return (i>j)?i:j;
}
int main() {
	int len1,len2;
	int dp[101][101],i,j,t;
	char a[101],b[101];
	for (t=1;gets(a)&&strcmp(a,"#");t++) {
		gets(b);
		len1=strlen(a);
		len2=strlen(b);
		for (i=0;i<=max(len1,len2);i++) dp[i][0]=dp[0][i]=0;
		for (i=1;i<=len1;i++)
			for (j=1;j<=len2;j++)
				dp[i][j]=(a[i-1]==b[j-1])?dp[i-1][j-1]+1:max(dp[i-1][j],dp[i][j-1]);
		printf("Case #%d: you can visit at most %d cities.\n",t,dp[len1][len2]);
	}
}