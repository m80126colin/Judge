#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

int t, k;
vector<int> v;

int main()
{
	int i, tmp;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d", &k);
		v.clear();
		for (i = 1; i <= k; i++)
			v.push_back(i);
		for (i = 0; i < k; i++)
		{
			if (i) putchar(' ');
			scanf("%d", &tmp);
			printf("%d", v[tmp]);
			v.erase(v.begin() + tmp);
		}
		puts("");
	}
}