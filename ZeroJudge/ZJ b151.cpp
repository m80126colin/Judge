#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(long long left, long long right)
{
	return left > right;
}

int main()
{
	vector <long long> v;
	int n, i;
	long long tmp, ans;
	while (scanf("%d", &n) != EOF)
	{
		ans = 0;
		v.clear();
		for (i = 0; i < n; i++)
		{
			scanf("%lld", &tmp);
			v.push_back(tmp);
		}
		make_heap(v.begin(), v.end(), cmp);
		while (v.size() > 1)
		{
			tmp = v.front();
			pop_heap(v.begin(), v.end(), cmp);
			v.pop_back();
			tmp += v.front();
			pop_heap(v.begin(), v.end(), cmp);
			v.pop_back();
			ans += tmp;
			v.push_back(tmp);
			push_heap(v.begin(), v.end(), cmp);
		}
		printf("%lld\n", ans);
	}
}