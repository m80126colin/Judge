/*
ID: m80126c2
PROG: ariprog
LANG: C++
*/
#include <fstream>
using namespace std;

ifstream cin("ariprog.in");
ofstream cout("ariprog.out");

bool ox[125001];
int dp[125001];

int main() {
	bool ox2=0;
	int i,j,n,m,a,b;
	cin>>n>>m;
	for (i=0;i<=m;i++) {
		for (j=i;j<=m;j++) {
			if (i*i+j*j<=2*m*m) ox[i*i+j*j]=1;
		}
	}
	for (i=j=0;i<=2*m*m;i++) {
		if (ox[i]) dp[j++]=i;
	}
	for (b=1;(n-1)*b<=2*m*m;b++) {
		for (a=0;a<j;a++) {
			if (dp[a]+(n-1)*b<=2*m*m) {
				for (i=0;i<=n-1;i++) {
					if (!ox[dp[a]+i*b]) break;
				}
				if (i==n) cout<<dp[a]<<" "<<b<<endl,ox2=1;
			}
		}
	}
	if (!ox2) cout<<"NONE"<<endl;
}