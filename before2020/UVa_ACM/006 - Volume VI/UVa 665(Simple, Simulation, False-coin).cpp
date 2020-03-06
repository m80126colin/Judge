/**
 *  @judge UVa
 *  @id 665
 *  @tag Simple, Simulation, False coin
 */
#include <iostream>
using namespace std;

int main()
{
	char ch;
	bool coin[101];
	int L[51], R[51];
	int m, n, p, k, ttl, ans;
	int i, j, x;
	for (cin >> m; m; m--)
	{
		cin >> n >> k;
		for (i = 1; i <= n; i++) coin[i] = 1;
		for (j = 1; j <= k; j++)
		{
			cin >> p;
			for (x = 1; x <= p; x++)
				cin >> L[x];
			for (x = 1; x <= p; x++)
				cin >> R[x];
			cin >> ch;
			if (ch == '=')
				for (x = 1; x <= p; x++)
					coin[L[x]] = coin[R[x]] = 0;
		}
		ttl = ans = 0;
		for (i = 1; i <= n; i++)
		{
			if (coin[i])
			{
				ttl++;
				ans = i;
			}
			if (ttl > 1) break;
		}
		if (ttl > 1 || ttl == 0) cout << 0 << endl;
		else cout << ans << endl;
		if (m > 1) cout << endl;
	}
}