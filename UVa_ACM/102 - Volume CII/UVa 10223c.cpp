#include <stdio.h>
int main() {
	int i,j;
	long long n,dp[22];
	dp[0]=1;
	for (i=1;i<22;i++) {
		dp[i]=0;
		for (j=i-1;j>=0;j--) dp[i]+=dp[j]*dp[i-j-1];
	}
	while (scanf("%lld",&n)!=EOF) {
		for (i=1;i<22;i++) {
			if (dp[i]==n) {
				printf("%d\n",i);
				break;
			}
		}
	}
}