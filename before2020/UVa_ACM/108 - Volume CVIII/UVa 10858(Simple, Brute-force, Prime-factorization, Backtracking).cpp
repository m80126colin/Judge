#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int n;
vector < vector <int> > M;

void sol(vector <int> tmp, int i, int x)
{
	if (1 == x)
	{
		if (tmp.size() > 1) M.push_back(tmp);
		return ;
	}
	for (; i <= x; i++)
	{
		if (0 == x % i)
		{
			vector <int> b = tmp;
			b.push_back(i);
			sol(b, i, x / i);
		}
	}
	return ;
}

int main()
{
	int i, j;
	vector <int> tmp;
	while (scanf("%d", &n), n)
	{
		M.clear();
		tmp.clear();
		sol(tmp, 2, n);
		printf("%d\n", M.size());
		for (i = 0; i < M.size(); i++)
		{
			for (j = 0; j < M[i].size(); j++)
			{
				if (j) putchar(' ');
				printf("%d", M[i][j]);
			}
			puts("");
		}
	}
}