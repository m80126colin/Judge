/*
ID: m80126c2
PROG: numtri
LANG: C++
*/
#include <fstream>
using namespace std;

ifstream cin("numtri.in");
ofstream cout("numtri.out");

int dp[2][1002];

int main() {
	int i,j,n;
	cin>>n;
	cin>>dp[1][1];
	for (i=2;i<=n;i++) {
		for (j=1;j<i;j++) dp[0][j]=dp[1][j];
		for (j=1;j<=i;j++) cin>>dp[1][j],dp[1][j]+=max(dp[0][j-1],dp[0][j]);
	}
	j=0;
	for (i=1;i<=n;i++) j=max(j,dp[1][i]);
	cout<<j<<endl;
}