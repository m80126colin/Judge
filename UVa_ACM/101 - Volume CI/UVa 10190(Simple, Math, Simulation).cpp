#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n, m;
vector <int> ans;

int main()
{
	int tmp;
	//freopen("UVa_10190.txt", "w+", stdout);
	while (cin >> n >> m)
	{
		if (n < 2 || m < 2 || n < m)
		{
			puts("Boring!");
			continue;
		}
		ans.clear();
		for (tmp = n; tmp > 1 && (tmp % m == 0); tmp /= m)
			ans.push_back(tmp);
		if (tmp > 1) printf("Boring!");
		else
		{
			if (ans.size() == 0 || (ans.size() >= 1 && ans[ans.size() - 1] != 1)) ans.push_back(1);
			for (int i = 0; i < ans.size(); i++)
			{
				if (i) putchar(' ');
				printf("%d", ans[i]);
			}
		}
		puts("");
	}
}