#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#define MAX 3
int bottle[MAX][MAX], s2[2 * MAX], minn;
string s1[2 * MAX]={"BCG","BGC","CBG","CGB","GBC","GCB"};

inline bool input()
{
	int i, j;
	for (i = j = 0; i < MAX; (j + 1< MAX)? j++: (i++, j = 0) )
		if (scanf("%d",&bottle[i][j]) == EOF) return 0;
	return 1;
}

inline int jdg(char ch)
{
	if (ch == 'B') return 0;
	else if (ch == 'G') return 1;
	else return 2;
}

inline int step(string x)
{
	int i, j, m, t;
	for (i = t = 0; i < MAX; i++)
	{
		m = jdg(x[i]);
		for (j = 0; j < MAX; j++)
			if (j != i) t += bottle[j][m];
	}
	return t;
}

int main()
{
	int i;
	while (input())
	{
		minn = 0;
		for (i = 0; i < 2 * MAX; i++)
		{
			s2[i] = step(s1[i]);
			if (s2[minn] > s2[i]) minn = i;
		}
		printf("%s %d\n", s1[minn].c_str(), s2[minn]);
	}
}