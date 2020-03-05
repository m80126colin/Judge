#include <stdio.h>
#include <iostream>
#include <set>
using namespace std;

set<int> comb;
set<int>::iterator it;
int way[3] = {135246, 513462, 326154};

int count(int a, int b)
{
	int i, temp[7], ans;
	for (i = 1; i <= 6; i++)
	{
		temp[i] = a % 10;
		a /= 10;
	}
	for (ans = 0; b; b /= 10)
	{
		ans *= 10;
		ans += temp[b % 10];
	}
	return ans;
}

void DFS(int x)
{
	comb.insert(x);
	int i, y;
	for (i = 0; i < 3; i++)
	{
		y = count(x, way[i]);
		if (comb.find(y) == comb.end())
			DFS(y);
	}
	return ;
}

int same(char x[], char y[], int type)
{
	int i, a[7];
	for (i = 6; i >= 1; i--)
	{
		a[i] = type % 10;
		type /= 10;
	}
	for (i = 1; i <= 6; i++)
		if (x[i] != y[a[i]])
			return 0;
	return 1;
}

int sol(char x[], char y[])
{
	for (it = comb.begin(); it != comb.end(); it++)
		if (same(x, y, *it))
			return 1;
	return 0;
}

int main()
{
	comb.clear();
	DFS(123456);

	int i;
	char temp[20], x[7], y[7];
	while (scanf("%s", temp) != EOF)
	{
		for (i = 1; i <= 6; i++)
		{
			x[i] = temp[i - 1];
			y[i] = temp[i + 5];
		}
		if (sol(x, y)) puts("TRUE");
		else puts("FALSE");
	}
}