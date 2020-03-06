/**
 *  @judge UVa
 *  @id 10393
 *  @tag Simple, Simulation
 */
#include <iostream>
#include <map>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

map<char, int> M;
int fin[11];
string W[1010];

bool cmp(string left, string right)
{
	if (left.size() != right.size()) return left.size() > right.size();
	return left < right;
}

int cantype(char ch)
{
	if (ch == ' ') return fin[5] || fin[6];
	return fin[ M[ch] ];
}

int main()
{
	int f, n;
	M.clear();
	M['q'] = M['a'] = M['z'] = 1;
	M['w'] = M['s'] = M['x'] = 2;
	M['e'] = M['d'] = M['c'] = 3;
	M['r'] = M['f'] = M['v'] = M['t'] = M['g'] = M['b'] = 4;
	M['y'] = M['h'] = M['n'] = M['u'] = M['j'] = M['m'] = 7;
	M['i'] = M['k'] = M[','] = 8;
	M['o'] = M['l'] = M['.'] = 9;
	M['p'] = M[';'] = M['/'] = 10;
	int i, j, tmp;
	while (scanf("%d%d", &f, &n) != EOF)
	{
		for (i = 1; i <= 10; i++) fin[i] = 1;
		for (i = 0; i < f; i++)
		{
			scanf("%d", &tmp);
			fin[tmp] = 0;
		}
		for (j = 0; j < n; j++)
		{
			cin >> W[j];
			for (i = 0; i < j; i++)
			{
				if (W[i] == W[j])
				{
					j--;
					n--;
					break;
				}
			}
			if (i != j) continue;
			for (i = 0; i < W[j].size() && cantype(W[j][i]); i++) ;
			if (i != W[j].size())
			{
				j--;
				n--;
			}
		}
		sort(W, W + n, cmp);
		/*if ( !(n && W[0].size()) ) puts("0");
		else
		{*/
			for (i = 0; i < n && W[i].size() == W[0].size(); i++) ;
			printf("%d\n", i);
			for (j = 0; j < i; j++) cout << W[j] << endl;
		/*}*/
	}
}