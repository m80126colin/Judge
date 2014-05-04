#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

class Poker
{
private:
	int Dir;
	string rank, dir, suit[4];
	map<string, int> card;
	vector<int> Player[4];
public:
	Poker()
	{
		dir = "SWNE";
		rank = "23456789TJQKA";
		suit[0] = "C";
		suit[1] = "D";
		suit[2] = "S";
		suit[3] = "H";
		int i, j;
		card.clear();
		for (i = 0; i < 4; i++)
			for (j = 0; j < rank.size(); j++)
				card[suit[i] + rank[j]] = i * 13 + j;
		card["#"] = 52;
		card["S"] = 3;
		card["W"] = 2;
		card["N"] = 1;
		card["E"] = 0;
		for (i = 0; i < 4; i++) Player[i].clear();
	}
	void Clear()
	{
		int i;
		for (i = 0; i < 4; i++)
			Player[i].clear();
	}
	void setPlayer(int index, string str)
	{
		Player[index].push_back(card[str]);
		return ;
	}
	int getPlayer(int index)
	{
		return Player[index].back();
	}
	void setDir(string str)
	{
		Dir = card[str];
		return ;
	}
	int getDir()
	{
		return Dir;
	}
	void Sort()
	{
		int i;
		for (i = 0; i < 4; i++)
			sort(Player[i].begin(), Player[i].end());
		return ;
	}
	void Print()
	{
		int i, j;
		for (i = 0; i < 4; i++)
		{
			printf("%c:", dir[i]);
			for (j = 0; j < Player[(i + Dir) % 4].size(); j++)
				printf(" %c%c", suit[Player[(i + Dir) % 4][j] / 13][0], rank[Player[(i + Dir) % 4][j] % 13]);
			puts("");
		}
	}
	friend istream& operator >> (istream& in, Poker& P)
	{
		int i;
		string s;
		P.Clear();
		cin >> s;
		if (s != "#")
		{
			P.setDir(s);
			cin >> s;
			for (i = 0; i < 26; i++)
				P.setPlayer(i % 4, s.substr(2 * i, 2));
			cin >> s;
			for (i = 26; i < 52; i++)
				P.setPlayer(i % 4, s.substr(2 * (i - 26), 2));
		}
		else P.setPlayer(0, s);
		return in;
	}
};

Poker Game;

int main()
{
	while (cin >> Game, Game.getPlayer(0) != 52)
	{
		Game.Sort();
		Game.Print();
	}
}