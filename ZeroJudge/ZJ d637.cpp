/*
Problem: d637
Language: CPP
Result: AC (6ms, 742KB) on ZeroJudge
Author: m80126colin at 2010-08-23 15:08:29
Solution: Dynamic Programming
*/
#include <iostream>
using namespace std;

struct feed{
	int a,b;
}f[10001];
int n,i,j,dp[101];

int main() {
	for (i=1;i<=100;dp[i++]=-1);
	for (i=scanf("%d",&n);i<=n;i++) {
		scanf("%d %d",&f[i].a,&f[i].b);
		for (j=100-f[i].a;j>=0;j--)
			if (dp[j]>=0) dp[j+f[i].a]=max(dp[j+f[i].a],dp[j]+f[i].b);
	}
	for (j=i=0;i<=100;i++) j=max(j,dp[i]);
	printf("%d\n",j);
}