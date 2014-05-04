#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 20010
long long dp[MAX], mx;
int from[MAX], n, m_left, m_right;

int main()
{
	int t, cnt, i;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		scanf("%d", &n);
		dp[1] = mx = 0;
		from[1] = m_left = m_right = 1;
		for (i = 2; i <= n; i++)
		{
			scanf("%lld", &dp[i]);
			from[i] = i - 1;
			if (dp[i - 1] + dp[i] >= dp[i])
			{
				dp[i] = dp[i - 1] + dp[i];
				from[i] = from[i - 1];
			}
			if (dp[i] > mx)
			{
				m_left = from[i];
				m_right = i;
				mx = dp[i];
			}
			else if (dp[i] == mx)
			{
				if (m_right - m_left < i - from[i])
				{
					m_left = from[i];
					m_right = i;
				}
				else if (m_right - m_left == i - from[i])
				{
					if (from[i] < m_left)
					{
						m_left = from[i];
						m_right = i;
					}
				}
			}
		}
		if (mx > 0) printf("The nicest part of route %d is between stops %d and %d\n", cnt, m_left, m_right);
		else printf("Route %d has no nice parts\n", cnt);
	}
}