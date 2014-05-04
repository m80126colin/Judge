#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

string cc;
vector<string> qu;
int q[9];

void MakeQueen()
{
	char tmp[9];
	int i;
	for (i = 0; i < 8; i++)
		tmp[i] = '0' + q[i + 1];
	tmp[8] = '\0';
	qu.push_back(tmp);
	return ;
}

int MyAbs(int x)
{
	if (x < 0) return -x;
	return x;
}

void Queen(int pos)
{
	if (pos > 8)
	{
		MakeQueen();
		return ;
	}
	int i;
	for (q[pos] = 1; q[pos] <= 8; q[pos]++)
	{
		for (i = 1; i < pos; i++)
			if ( q[i] == q[pos] || MyAbs(q[i] - q[pos]) == MyAbs(i - pos) )
				break ;
		if (i == pos) Queen(pos + 1);
	}
	q[pos] = 0;
	return ;
}

int input()
{
	char tmp[9];
	int i;
	for (i = 0; i < 8; i++)
	{
		cin >> tmp[i];
		if (cin.eof())
			return EOF;
	}
	tmp[8] = '\0';
	cc = tmp;
	return 0;
}

int Hamming(int pos)
{
	int i, cnt = 0;
	for (i = 0; i < 8; i++)
	{
		if (cc[i] != qu[pos][i])
			cnt++;
	}
	return cnt;
}

int main()
{
	int i, mn, t;
	qu.clear();
	Queen(1); // make queen
	for (t = 1; input() != EOF; t++)
	{
		mn = 8;
		for (i = 0; i < qu.size(); i++)
			mn = min(mn, Hamming(i));
		printf("Case %d: %d\n", t, mn);
	}
}