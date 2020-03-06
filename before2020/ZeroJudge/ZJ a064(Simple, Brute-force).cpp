/**
 *  @judge ZeroJudge
 *  @id a064
 *  @tag Simple, Brute force
 */
#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
	int n, i, j, k;
	long long ans;
	map <int, int> M;
	vector <int> set;
	while (scanf("%d", &n) != EOF)
	{
		M.clear();
		set.clear();
		for (i = 0; i < n; i++)
		{
			scanf("%d", &k);
			set.push_back(k);
		}
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				for (k = 0; k < n; k++)
					M[set[i] * set[j] + set[k]]++;
		ans = 0;
		for (i = 0; i < n; i++)
			if (set[i] != 0)
				for (j = 0; j < n; j++)
					for (k = 0; k < n; k++)
						ans += M[set[i] * (set[j] + set[k])];
		printf("%lld\n", ans);
	}
}