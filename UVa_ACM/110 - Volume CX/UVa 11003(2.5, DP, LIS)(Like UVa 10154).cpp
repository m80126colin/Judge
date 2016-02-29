#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 1010
#define MAXN 1000000000
struct box
{
	int w, L;
	box(){ w = L = 0; }
	box(int w, int L): w(w), L(L){}
	bool operator < (const box& B) const { return L < B.L; }
}B[MAX];
int dp[MAX], n, ans;

int main()
{
	int i, j;
	while (scanf("%d", &n), n)
	{
		for (i = 0; i < n; i++)
			scanf("%d%d", &B[n - i - 1].w, &B[n - i - 1].L);
		for (i = 1; i <= n; i++)
			dp[i] = MAXN;
		ans = dp[0] = 0;
		for (i = 0; i < n; i++)
			for (j = ans; j >= 0; j--)
				if (B[i].L >= dp[j] && dp[j + 1] >= dp[j] + B[i].w)
				{
					dp[j + 1] = dp[j] + B[i].w;
					ans = max(ans, j + 1);
				}
		printf("%d\n", ans);
	}
}