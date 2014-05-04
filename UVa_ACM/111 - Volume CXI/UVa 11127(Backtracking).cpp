#include <stdio.h>
#include <iostream>
using namespace std;

int n, cnt;
char tmp;
char s[50];

int MyStrcmp(int begin1, int begin2, int len)
{
	int i;
	for (i = 0; i < len; i++)
		if (s[begin1 + i] != s[begin2 + i])
			return 0;
	return 1;
}

int CheckTriple(int pos)
{
	int i, len;
	for (i = pos - 1; i >= 0; i--)
	{
		len = pos - i;
		if (3 * len > pos)
			break;
		if (MyStrcmp(i, i - len, len) && MyStrcmp(i, i - 2 * len, len))
			return 1;
	}
	return 0;
}

void DFS(int pos)
{
	if (pos >= n)
	{
		cnt++;
		return ;
	}
	if (s[pos] == '*')
	{
		s[pos] = '0';
		if (!CheckTriple(pos + 1))
			DFS(pos + 1);
		s[pos] = '1';
		if (!CheckTriple(pos + 1))
			DFS(pos + 1);
		s[pos] = '*';
	}
	else
	{
		if (!CheckTriple(pos + 1))
			DFS(pos + 1);
	}
	return ;
}

int main()
{
	int i, t;
	for (t = 1; scanf("%d", &n), n; t++)
	{
		for (i = 0; i < n; i++)
		{
			cin >> tmp;
			s[i] = tmp;
		}
		s[n] = '\0';
		cnt = 0;
		DFS(0);
		printf("Case %d: %d\n", t, cnt);
	}
}