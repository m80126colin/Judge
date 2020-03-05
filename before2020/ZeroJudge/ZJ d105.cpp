#include <iostream>
using namespace std;

int main() {
	int dp[31][31],m,n,i,j;
	memset(dp,0,sizeof(dp));
	dp[1][0]=1;
	cin>>n>>m;
	for (j=1;j<=m;j++) {
		for (i=1;i<=n;i++) {
			if (i+1>n) dp[i][j]+=dp[1][j-1];
			else dp[i][j]+=dp[i+1][j-1];
			if ((i-1)==0) dp[i][j]+=dp[n][j-1];
			else dp[i][j]+=dp[i-1][j-1];
		}
	}
	cout<<dp[1][m]<<endl;
}