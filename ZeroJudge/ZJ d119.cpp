#include <iostream>
using namespace std;

int main() {
	long long c[10]={1,5,10,20,50,100,200,500,1000,2000};
	static long long n,i,j,dp[50001];
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for (i=0;i<10;i++) {
		for (j=c[i];j<=50000;j++) dp[j]+=dp[j-c[i]];
	}
	while (cin>>n&&n) {
		while (cin.peek()!='\n') {
			cin>>i;
			n+=i;
		}
		cout<<dp[n]-1<<endl;
	}
}