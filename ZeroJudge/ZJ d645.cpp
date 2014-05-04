/*
Problem: d645
Language: CPP
Result: AC (14ms, 724KB) on ZeroJudge
Author: m80126colin at 2010-08-23 17:20:26
Solution: DP
*/
#include <iostream>
using namespace std;

struct feed{
	int a,b,c;
}f[10001];
int n,m,i,j,k,dp[1001];

int main() {
	for (i=1;i<=1000;dp[i++]=-1);
	for (i=scanf("%d %d",&n,&m)-1;i<=n;i++) {
		scanf("%d %d %d",&f[i].b,&f[i].a,&f[i].c);
		if (f[i].c>0) {
			for (k=1;k<=f[i].c;k++) {
				for (j=m-f[i].a;j>=0;j--) if (dp[j]>=0) dp[j+f[i].a]=max(dp[j+f[i].a],dp[j]+f[i].b);
			}
		}
		else {
			for (j=0;j<=m;j++) if (dp[j]>=0&&j+f[i].a<=m) dp[j+f[i].a]=max(dp[j+f[i].a],dp[j]+f[i].b);
		}
	}
	for (j=i=0;i<=m;i++) j=max(j,dp[i]);
	printf("%d\n",j);
}