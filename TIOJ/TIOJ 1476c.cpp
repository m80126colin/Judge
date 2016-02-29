#include <stdio.h>

int main() {
	int i,dp[46];
	dp[0]=dp[1]=1;
	for (i=2;i<46;i++) dp[i]=dp[i-1]+dp[i-2];
	scanf("%d",&i);
	printf("%d\n",dp[i]);
}