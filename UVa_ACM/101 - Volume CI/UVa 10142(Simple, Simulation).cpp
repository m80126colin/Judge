#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct vote
{
	int point, v[30];
	vote() { point = 0; }
}people[1010];
int fail[30];
int n, m;

int Count()
{
	int i, mn, mx;
	int count[30];
	for (i = 0; i < n; i++)
		count[i] = 0;
	for (i = 0; i < m; i++)
	{
		while (people[i].point < n && fail[people[i].v[people[i].point] - 1])
			people[i].point++;
		count[people[i].v[people[i].point] - 1]++;
	}
	mn = mx = -1;
	for (i = 0; i < n; i++)
		if (!fail[i])
		{
			if (mn < 0 || (mn >= 0 && mn > count[i]))
				mn = count[i];
			if (mx < 0 || (mx >= 0 && count[i] > mx))
				mx = count[i];
		}
	for (i = 0; i < n; i++)
		if (!fail[i] && mn != count[i])
			break;
	if (i == n)
		return 0;
	if ((double) mx >= (double) m / 2)
	{
		for (i = 0; i < n; i++)
			if (!fail[i] && mx != count[i])
				fail[i] = 1;
		return 0;
	}
	for (i = 0; i < n; i++)
		if (!fail[i] && mn == count[i])
			fail[i] = 1;
	return 1;
}

int main()
{
	string temp;
	vector<string> Name;
	int t, i;
	for (scanf("%d", &t); t; t--)
	{
		memset(fail, 0, sizeof(fail));
		scanf("%d", &n);
		cin.ignore(1);
		Name.clear();
		for (i = 0; i < n; i++)
		{
			getline(cin, temp);
			Name.push_back(temp);
		}
		for (m = 0; cin.peek() != '\n'; m++)
		{
			if (cin.peek() == EOF)
				break;
			people[m].point = 0;
			for (i = 0; i < n; i++)
				scanf("%d", &people[m].v[i]);
			cin.ignore(1);
		}
		while (Count()) ;
		for (i = 0; i < n; i++)
			if (!fail[i])
				printf("%s\n", Name[i].c_str());
		if (t > 1) puts("");
	}
}