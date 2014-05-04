#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

#define MAX 500010
int v[MAX], dp[MAX], len;
vector<int> s;

void LIS()
{
	int i, tmp;
	for (i = 1; i < len; i++)
	{
		tmp = v[i];
		if (tmp > s.back())
		{
			s.push_back(tmp);
			dp[i] = s.size();
		}
		else
		{
			dp[i] = lower_bound(s.begin(), s.end(), tmp) - s.begin() + 1;
			s[dp[i] - 1] = tmp;
		}
	}
	return ;
}

void print_LIS()
{
	int i, mx = s.size();
	s.clear();
	for (i = len; i; i--)
	{
		if (dp[i - 1] == mx)
		{
			s.push_back(v[i - 1]);
			mx--;
		}
	}
	while (!s.empty())
	{
		printf("%d\n", s.back());
		s.pop_back();
	}
	return ;
}

int main()
{
	s.clear();
	for (len = 0; scanf("%d", &v[len]) != EOF; len++);
	s.push_back(v[0]);
	dp[0] = 1;
	LIS();
	printf("%d\n-\n", s.size());
	print_LIS();
}