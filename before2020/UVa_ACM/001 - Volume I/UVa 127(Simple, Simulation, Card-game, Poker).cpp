#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

class Accordian
{
private:
	map<string, int> card;
	vector<int> stack[52];
	vector< vector<int>* > card_heap;
public:
	Accordian()
	{
		card.clear();
		int i, j;
		string suit[4] = {"C", "D", "H", "S"}, rank = "A23456789TJQK";
		for (i = 0; i < 4; i++)
			for (j = 0; j < rank.size(); j++)
				card[ rank[j] + suit[i] ] = i * 13 + j;
		card["#"] = 52;
		card_heap.clear();
		for (i = 0; i < 52; i++)
		{
			stack[i].clear();
			card_heap.push_back( &stack[i] );
		}
	}
	void Clear()
	{
		int i;
		card_heap.clear();
		for (i = 0; i < 52; i++)
		{
			stack[i].clear();
			card_heap.push_back( &stack[i] );
		}
		return ;
	}
	void setStack(int index, string str)
	{
		stack[index].push_back(card[str]);
		return ;
	}
	int getStack(int index)
	{
		return stack[index].back();
	}
	bool Match(int ai, int bi)
	{
		if (ai == bi) return 0;
		int a = card_heap[ai]->back(), b = card_heap[bi]->back();
		return (a / 13 == b / 13) || (a % 13 == b % 13);
	}
	void Move(int ai, int bi)
	{
		int a = card_heap[ai]->back();
		card_heap[ai]->pop_back();
		card_heap[bi]->push_back(a);
		return ;
	}
	bool OneMove()
	{
		int i;
		for (i = 0; i < card_heap.size(); i++)
		{
			if (i - 3 >= 0 && Match(i, i - 3))
			{
				Move(i, i - 3);
				break;
			}
			else if (i - 1 >= 0 && Match(i, i - 1))
			{
				Move(i, i - 1);
				break;
			}
		}
		if (i == card_heap.size()) return 0;
		if (card_heap[i]->empty())
			card_heap.erase(card_heap.begin() + i);
		return 1;
	}
	void Play()
	{
		while ( OneMove() ) ;
		return ;
	}
	void Print()
	{
		if (card_heap.size() == 1)
			printf("1 pile remaining:");
		else printf("%d piles remaining:", card_heap.size());
		int i;
		for (i = 0; i < card_heap.size(); i++)
			printf(" %d", card_heap[i]->size());
		puts("");
		return ;
	}
	friend istream& operator >> (istream& in, Accordian& A)
	{
		A.Clear();
		string Temp;
		cin >> Temp;
		A.setStack(0, Temp);
		if (Temp != "#")
		{
			int i;
			for (i = 1; i < 52; i++)
			{
				cin >> Temp;
				A.setStack(i, Temp);
			}
		}
		return in;
	}
};

Accordian Game;

int main()
{
	while (cin >> Game, Game.getStack(0) != 52)
	{
		Game.Play();
		Game.Print();
	}
}