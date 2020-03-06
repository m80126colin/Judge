/**
 *  @judge UVa
 *  @id 151
 *  @tag Simple, Josephus problem
 */
#include <iostream>
#define MAX 110
using namespace std;

int main()
{
	int n, m, dp[MAX], i;
	while (cin >> n, n)
	{
		for (m = 1; m; m++)
		{
			dp[1] = 0;
			for (i = 2; i <= n - 1; i++)
			{
				dp[i] = (dp[i-1] + m) % i;
			}
			dp[n] = (dp[n - 1] + 1) % n;
			if (dp[n-1] == 11)
			{
				cout << m <<endl;
				break;
			}
		}
	}
}