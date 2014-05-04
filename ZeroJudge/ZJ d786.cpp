#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int a,b,i,dp[101];
	double av;
	for (cin>>a;a;a--) {
		dp[0]=0;
		for (cin>>b,i=1;i<=b;i++) cin>>dp[i],dp[0]+=dp[i];
		av=(double) dp[0] /(double) b;
		cout<<fixed<<setprecision(2)<<av<<endl;
	}
}