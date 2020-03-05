#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

#define COIN 12
#define TIME  3
bool ox[COIN];
int coin[COIN];
string s[3];

void setStatus(int Scoin, int Sox)
{
	int i, j;
	for (i = 0; i < 2; i++)
		for (j = 0; j < s[i].size(); j++)
		{
			coin[s[i][j] - 'A'] = Scoin;
			ox[s[i][j] - 'A'] = Sox;
		}
	return ;
}

void setCoin(int w)
{
	int i, j;
	for (i = 0; i < 2; i++)
		for (j = 0; j < s[i].size(); j++)
			if (!ox[s[i][j] - 'A'])
				coin[s[i][j] - 'A'] += w * ((i == 1) * 1 + (-1) * (i == 0));
	return ;
}

int main()
{
	int i, j, n, fake;
	for (cin >> n; n; n--)
	{
		for (i = 0; i < COIN; i++)
			ox[i] = coin[i] = 0;
		for (i = 0; i < TIME; i++)
		{
			for (j = 0; j < 3; j++)
				cin >> s[j];
			if (s[2] == "even")
				setStatus(0, 1);
			else if (s[2] == "up")
				setCoin(1);
			else setCoin(-1);
		}
		for (i = fake = 0; i < COIN; i++)
		{
			if (abs(coin[i]) > abs(coin[fake])) fake = i;
			else ox[i] = 1;
		}
		printf("%c is the counterfeit coin and it is %s.\n", fake + 'A', ((coin[fake] > 0) ? "light" : "heavy"));
	}
}