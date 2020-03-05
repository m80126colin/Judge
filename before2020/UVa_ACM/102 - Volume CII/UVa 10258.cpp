#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define N 110
#define M 15
using namespace std;

struct team
{
	int num, ttl, id, uped;
	int solve[M], score[M];
}T[N];

bool cmp(team left, team right)
{
	if (left.uped != right.uped) return left.uped > right.uped;
	if (left.num != right.num) return left.num > right.num;
	if (left.ttl != right.ttl) return left.ttl < right.ttl;
	return left.id < right.id;
}

int main()
{
	int t, i, j, k;
	char s[5];
	for (scanf("%d", &t), cin.ignore(2); t; t--)
	{
		memset(T, 0, sizeof(T));
		for (i = 1; i < N; i++) T[i].id = i;
		while (scanf("%d%d%d%s", &i, &j, &k, s))
		{
			T[i].uped = 1;
			if (!T[i].solve[j])
			{
				if (s[0] == 'C')
				{
					T[i].score[j] += k;
					T[i].solve[j] = 1;
					T[i].ttl += T[i].score[j];
					T[i].num++;
				}
				else if (s[0] == 'I')
					T[i].score[j] += 20;
			}
			cin.ignore(1);
			if (cin.peek() == '\n' || cin.peek() == EOF) break;
		}
		sort(T + 1, T + N, cmp);
		for (i = 1; i < N; i++)
		{
			if (T[i].uped)
			{
				printf("%d %d %d\n", T[i].id, T[i].num, T[i].ttl);
			}
		}
		if (t > 1) puts("");
	}
}