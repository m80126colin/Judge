/*
ID: m80126c2
PROG: sprime
LANG: C++
*/
#include <fstream>
#include <cstring>
#define mMAX 100
#define MAX 10000
using namespace std;

ifstream cin("sprime.in");
ofstream cout("sprime.out");

bool p[MAX];
int pr[10000],dp[8][100];

inline bool ispr(const int& x) {
	int i;
	if (x/10000) {
		for (i=1;i<=pr[0];i++) {
			if (!(x%pr[i])) return 0;
		}
		return 1;
	}
	else return !p[x];
}

int main() {
	int i,j,k,n;
	p[1]=1;
	for (i=2;i<mMAX;i++) {
		if (!p[i]) {
			for (j=i;i*j<MAX;j++) p[i*j]=1;
		}
	}
	for (pr[0]=0,i=2;i<MAX;i++) {
		if (!p[i]) pr[0]++,pr[pr[0]]=i;
	}
	cin>>n;
	memset(dp,0,sizeof(dp));
	for (dp[1][0]=4,dp[1][1]=2,dp[1][2]=3,dp[1][3]=5,dp[1][4]=7,k=2;k<=n;k++) {
		for (i=1,dp[k][0]=0;i<=dp[k-1][0];i++) {
			for (j=1;j<=9;j++) {
				if ( ispr(dp[k-1][i]*10+j) ) {
					dp[k][0]++;
					dp[k][dp[k][0]]=dp[k-1][i]*10+j;
				}
			}
		}
	}
	for (i=1;i<=dp[n][0];i++) cout<<dp[n][i]<<endl;
}