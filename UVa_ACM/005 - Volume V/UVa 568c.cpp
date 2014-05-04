#include <stdio.h>
int main() {
	int n,dp[10001];
	dp[0]=1;
	for (n=1;n<=10000;n++) {
		dp[n]=dp[n-1]*n;
		while (!(dp[n]%10)) dp[n]/=10;
		dp[n]%=100000;
	}
	while (scanf("%d",&n)!=EOF) printf("%5d -> %d\n",n,dp[n]%10);
}