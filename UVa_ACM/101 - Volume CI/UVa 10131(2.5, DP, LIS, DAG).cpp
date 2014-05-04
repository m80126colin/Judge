#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1010
struct ele
{
	int i, w, s;
	ele(){ i = w = s = 0; }
	ele(int i, int w, int s): i(i), w(w), s(s) {}
	bool operator < (const ele& e) const
	{
		if (w != e.w) return w > e.w;
		else if (s != e.s) return s < e.s;
		return i > e.i;
	}
}E[MAX];
int dp[MAX], path[MAX], n;

int main()
{
	int w, s, i, j, ans, head;
	for (n = 0; scanf("%d%d", &w, &s) != EOF; n++)
		E[n] = ele(n, w, s), dp[n] = 1;
	sort(E, E + n);
	ans = head = 0;
	for (j = 1; j < n; j++)
		for (i = 1; i < j; i++)
			if (E[i].w > E[j].w && E[i].s < E[j].s)
				if (dp[j] < dp[i] + 1)
				{
					dp[j] = dp[i] + 1;
					path[j] = i;
					if (ans < dp[j])
					{
						ans = dp[j];
						head = j;
					}
				}
	for (printf("%d\n", ans); ans; ans--)
	{
		printf("%d\n", E[head].i + 1);
		head = path[head];
	}
}