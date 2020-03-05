#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;

#define MAX 100010
set<int> S;
int t, cnt, n, k, a, b, c, r;
int m[MAX], ox[MAX], res[MAX];

int main()
{
	freopen("find_the_mintxt.txt", "r", stdin);
	freopen("find_the_mintxt.out", "w+", stdout);
	int i;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		scanf("%d%d", &n, &k);
		scanf("%d%d%d%d", &a, &b, &c, &r);
		S.clear();
		for (i = 0; i <= k; i++)
		{
			ox[i] = 1;
			S.insert(i);
		}
		m[0] = a;
		if (m[0] >= 0 && m[0] <= k)
		{
			ox[m[0]]--;
			if (ox[m[0]] == 0) S.erase(m[0]);
		}
		for (i = 1; i < k; i++)
		{
			m[i] = (long long) ((long long) b * m[i - 1] + c) % r;
			if (m[i] >= 0 && m[i] <= k)
			{
				ox[m[i]]--;
				if (ox[m[i]] == 0) S.erase(m[i]);
			}
		}
		for (i = 0; i < k; i++)
		{
			res[i] = *S.begin();
			ox[res[i]]--;
			if (ox[res[i]] == 0) S.erase(res[i]);
			if (m[i] >= 0 && m[i] <= k)
			{
				ox[m[i]]++;
				if (ox[m[i]] > 0) S.insert(m[i]);
			}
		}
		res[k] = *S.begin();
		printf("Case #%d: %d\n", cnt, res[(n - (k + 1)) % (k + 1)]);
	}
}