/**
 *  @judge UVa
 *  @id 10067
 *  @tag Simple, BFS, Implicit graph
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int state[10001];
string S, T;

void input(string &a)
{
	char ch;
	a = "";
	int i;
	for (i = 0; i < 4; i++)
	{
		cin >> ch;
		a += ch;
	}
	return ;
}

int BFS()
{
	state[atoi(S.c_str())] = 0;
	queue<string> Q;
	Q.push(S);
	int i;
	while (!Q.empty())
	{
		string q = Q.front();
		Q.pop();
		for (i = 0; i < 4; i++)
		{
			string r = q;
			r[i] = (r[i] - '0' + 1) % 10 + '0';
			if (state[atoi(r.c_str())] == -1)
			{
				state[atoi(r.c_str())] = state[atoi(q.c_str())] + 1;
				Q.push(r);
			}
			r = q;
			r[i] = (r[i] - '0' + 9) % 10 + '0';
			if (state[atoi(r.c_str())] == -1)
			{
				state[atoi(r.c_str())] = state[atoi(q.c_str())] + 1;
				Q.push(r);
			}
			if (state[atoi(T.c_str())] >= 0)
				return state[atoi(T.c_str())];
		}
	}
	return state[atoi(T.c_str())];
}

int main()
{
	int t, i, n;
	string tmp;
	for (scanf("%d", &t); t; t--)
	{
		input(S);
		input(T);
		memset(state, -1, sizeof(state));
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			input(tmp);
			state[atoi(tmp.c_str())] = -2;
		}
		printf("%d\n", BFS());
	}
}