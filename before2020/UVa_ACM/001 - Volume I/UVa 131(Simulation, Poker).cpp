/**
 *  @judge UVa
 *  @id 131
 *  @tag Simulation, Poker
 */
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

struct poker
{
	int a[2];
};
string show[9] = 
{
	"straight-flush",
	"four-of-a-kind",
	"full-house",
	"flush",
	"straight",
	"three-of-a-kind",
	"two-pairs",
	"one-pair",
	"highest-card"
};
string ff[2] = {"0A23456789TJQK", "CDHS"};
string tmp;
poker hand[5], deck[5], new_hand[5];

bool cmp(poker left, poker right)
{
	return left.a[0] < right.a[0];
}

int update()
{
	int i, j;
	sort(new_hand, new_hand + 5, cmp);
	for (i = 0; i < 8; i++)
	{
		//straight-flush
		if (i == 0)
		{
			int ox = 1;
			for (j = 1; j < 5; j++)
				if (new_hand[j - 1].a[1] != new_hand[j].a[1])
				{
					ox = 0;
					break;
				}
			for (j = 2; j < 5; j++)
				if (new_hand[j - 1].a[0] + 1 != new_hand[j].a[0])
				{
					ox = 0;
					break;
				}
			if ( !(new_hand[4].a[0] == 13 && new_hand[0].a[0] == 1) && new_hand[0].a[0] + 1 != new_hand[1].a[0] ) ox = 0;
			if (ox) return i;
		}
		//four-of-a-kind
		else if (i == 1)
		{
			if (new_hand[1].a[0] != new_hand[2].a[0] || new_hand[2].a[0] != new_hand[3].a[0])
				continue;
			if (new_hand[0].a[0] == new_hand[1].a[0] || new_hand[3].a[0] == new_hand[4].a[0])
				return i;
		}
		//full-house
		else if (i == 2)
		{
			if (new_hand[0].a[0] != new_hand[1].a[0] || new_hand[3].a[0] != new_hand[4].a[0])
				continue;
			if (new_hand[1].a[0] == new_hand[2].a[0] || new_hand[2].a[0] == new_hand[3].a[0])
				return i;
		}
		//flush
		else if (i == 3)
		{
			int ox = 1;
			for (j = 1; j < 5; j++)
				if (new_hand[j - 1].a[1] != new_hand[j].a[1])
				{
					ox = 0;
					break;
				}
			if (ox) return i;
		}
		//straight
		else if (i == 4)
		{
			int ox = 1;
			for (j = 2; j < 5; j++)
				if (new_hand[j - 1].a[0] + 1 != new_hand[j].a[0])
				{
					ox = 0;
					break;
				}
			if ( !(new_hand[4].a[0] == 13 && new_hand[0].a[0] == 1) && new_hand[0].a[0] + 1 != new_hand[1].a[0] ) ox = 0;
			if (ox) return i;
		}
		//three-of-a-kind
		else if (i == 5)
		{
			int tt = new_hand[2].a[0], cnt = 0;
			for (j = 0; j < 5; j++)
				if (new_hand[j].a[0] == tt) cnt++;
			if (cnt == 3) return i;
		}
		//two-pairs
		else if (i == 6)
		{
			int cnt = 0;
			for (j = 1; j < 5; j++)
				if (new_hand[j - 1].a[0] == new_hand[j].a[0]) cnt++;
			if (cnt == 2) return i;
		}
		//one-pair
		else if (i == 7)
		{
			int cnt = 0;
			for (j = 1; j < 5; j++)
				if (new_hand[j - 1].a[0] == new_hand[j].a[0]) cnt++;
			if (cnt == 1) return i;
		}
	}
	return i;
}

int best()
{
	int i, j, k, now, ans = 8;
	for (i = 0; i < 32; i++)
	{
		for (j = k = 0; j < 5; j++)
		{
			if (i & (1 << j))
				new_hand[j] = deck[k++];
			else
				new_hand[j] = hand[j];
		}
		now = update();
		if (now < ans) ans = now;
	}
	return ans;
}

int main()
{
	int i, j, k;
	while (cin >> tmp)
	{
		cout << "Hand: " << tmp;
		for (j = 0; j < 2; j++)
		{
			for (k = 0; k < ff[j].size(); k++)
				if (tmp[j] == ff[j][k])
					break;
			hand[0].a[j] = k;
		}
		for (i = 1; i < 5; i++)
		{
			cin >> tmp;
			cout << " " << tmp;
			for (j = 0; j < 2; j++)
			{
				for (k = 0; k < ff[j].size(); k++)
					if (tmp[j] == ff[j][k])
						break;
				hand[i].a[j] = k;
			}
		}
		cin >> tmp;
		cout << " Deck: " << tmp;
		for (j = 0; j < 2; j++)
		{
			for (k = 0; k < ff[j].size(); k++)
				if (tmp[j] == ff[j][k])
					break;
			deck[0].a[j] = k;
		}
		for (i = 1; i < 5; i++)
		{
			cin >> tmp;
			cout << " " << tmp;
			for (j = 0; j < 2; j++)
			{
				for (k = 0; k < ff[j].size(); k++)
					if (tmp[j] == ff[j][k])
						break;
				deck[i].a[j] = k;
			}
		}
		cout << " Best hand: " << show[best()] << endl;
	}
}