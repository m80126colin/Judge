#include <iostream>
using namespace std;

int main() {
	static bool dp[10001][21][21];
	int cnt,t,n,i,j,l,k,a[10001],tmp,cc;
	for (cin>>t,cnt=1;cnt<=t;cnt++) {
		cin>>n>>k;
		cc=k+1;
		tmp=(n/2)*2;
		for (i=1;i<=n;i++) cin>>a[i];
		memset(dp,0,sizeof(dp));
		dp[0][0][0]=1;
		for (i=0;i<=n/2;i++) {
			for (j=0;j<=k;j++) {
				for (l=0;l<=k;l++) {
					if (dp[i][j][l]) {
						if (n-(2*i+j+l)>1) {
							if (a[1+i+j]==a[n-i-l]) dp[i+1][j][l]=1;
							else dp[i][j+1][l]=dp[i][j][l+1]=1;
						}
						else cc=min(j+l,cc);
					}
				}
			}
		}
		cout<<"Case "<<cnt<<": ";
		if (cc>k) cout<<"Too difficult"<<endl;
		else if (cc>0) cout<<cc<<endl;
		else cout<<"Too easy"<<endl;
	}
}