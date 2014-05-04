#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MAX 5
int mod[MAX] = {1, 10, 100, 1000, 10000};
vector<string> ans[MAX];

string make_str(int num, int len)
{
	string s;
	for (s = ""; num; num /= 10)
		s = (char) ('0' + num % 10) + s;
	while (s.size() < len)
		s = '0' + s;
	return s;
}

int main()
{
	int i, j, k;
	for (i = 0; i < MAX; i++)
	{
		ans[i].clear();
		for (j = 0; j / mod[i] < mod[i]; j++)
		{
			k = j / mod[i] + j % mod[i];
			if (k * k == j) ans[i].push_back(make_str(j, i << 1));
		}
	}
	while (scanf("%d", &i) != EOF)
	{
		i >>= 1;
		for (j = 0; j < ans[i].size(); j++)
			puts(ans[i][j].c_str());
	}
}