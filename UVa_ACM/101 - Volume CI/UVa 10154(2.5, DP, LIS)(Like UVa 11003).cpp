#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 5610
#define MAXN 1000000000
struct tur
{
	int w, L;
	tur() { w = L = 0; }
	tur(int a, int b): w(a), L(b){}
	bool operator < (const tur& t) const { return L < t.L; }
}T[MAX];
int dp[MAX], n, ans;

int main()
{
	int i, j, ans;
	int a, b;
	for (n = 0; scanf("%d%d", &a, &b) != EOF; n++) T[n] = tur(a, b), dp[n] = MAXN;
	sort(T, T + n);
	ans = dp[0] = 0, dp[n] = MAXN;
	for (j = 0; j < n; j++)
		for (i = ans; i >= 0; i--)
			if (T[j].L > dp[i] + T[j].w && dp[i + 1] > dp[i] + T[j].w)
			{
				dp[i + 1] = dp[i] + T[j].w;
				ans = max(ans, i + 1);
			}
	printf("%d\n", ans);
}