#include <iostream>
using namespace std;

int main() {
	int a,b,i,dp[101],dp2[101],m;
	for (cin>>a;a;a--) {
		dp[0]=dp2[0]=m=0;
		for (cin>>b,i=1;i<=b;i++) {
			cin>>dp[i];
			dp2[i]=(dp2[i-1]+dp[i]>0)*(dp2[i-1]+dp[i]);
			m=max(m,dp2[i]);
		}
		if (!m) {
			m=dp[1];
			for (i=2;i<=b;i++) m=max(m,dp[i]);
		}
		cout<<m<<endl;
	}
}