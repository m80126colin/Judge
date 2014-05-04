#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct bead
{
	char *s;
	int d;
	bead(char *s, int d): s(s), d(d) {}
};

#define MAX 35000
char s0[MAX], tt[MAX];
vector<bead> V;

bool cmp(bead left, bead right)
{
	int i;
	for (i = 0; i < min(strlen(left.s), strlen(right.s)); i++)
		if (left.s[i] != right.s[i])
			return left.s[i] < right.s[i];
	return left.d < right.d;
}

int main()
{
	int t, i;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%s", s0);
		V.clear();
		strcpy(tt, s0);
		strcat(tt, s0);
		for (i = 0; i < strlen(tt) / 2; i++)
			V.push_back(bead(tt + i, i + 1));
		sort(V.begin(), V.end(), cmp);
		printf("%d\n", V[0].d);
	}
}