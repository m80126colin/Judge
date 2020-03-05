#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>
#include <vector>
#include <string>
using namespace std;

string suit[4] = {"C", "D", "H", "S"}, rank = "A23456789TJQK";

class Clock
{
private:
	int NumOfOn;
	map<string, int> card;
	vector<int> stack[13];
public:
	Clock()
	{
		card.clear();
		int i, j;
		for (i = 0; i < 4; i++)
			for (j = 0; j < rank.size(); j++)
				card[ rank[j] + suit[i] ] = i * 13 + j;
		card["#"] = 52;
		for (i = 0; i < 13; i++)
			stack[i].clear();
		NumOfOn = 0;
	}
	void Clear()
	{
		int i;
		for (i = 0; i < 13; i++)
			stack[i].clear();
		NumOfOn = 0;
		return ;
	}
	void setStack(int index, string str)
	{
		stack[index].insert(stack[index].begin(), card[str]);
		return ;
	}
	int getStack(int index)
	{
		return stack[index].back();
	}
	int Play()
	{
		int temp;
		int state = 12;
		while (!stack[state].empty())
		{
			temp = stack[state].back();
			stack[state].pop_back();
			// printf("pop %c%c\n", rank[temp % 13], suit[temp / 13][0]);
			state = temp % 13;
			NumOfOn++;
		}
		return temp;
	}
	void Print(int last)
	{
		printf("%02d,%c%c\n", NumOfOn, rank[last % 13], suit[last / 13][0]);
		return ;
	}
	friend istream& operator >> (istream& in, Clock& A)
	{
		A.Clear();
		string Temp;
		cin >> Temp;
		A.setStack(12, Temp);
		if (Temp != "#")
		{
			int i;
			for (i = 50; i >= 0; i--)
			{
				cin >> Temp;
				A.setStack(i % 13, Temp);
			}
		}
		return in;
	}
};

Clock Game;

int main()
{
	int last;
	while (cin >> Game, Game.getStack(12) != 52)
	{
		last = Game.Play();
		Game.Print(last);
	}
}