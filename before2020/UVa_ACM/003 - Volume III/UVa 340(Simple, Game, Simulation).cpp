#include <stdio.h>
#include <iostream>
using namespace std;

int N;
class AB
{
public:
	int arr[1010];
	int num[10];
	bool operator != (const int& X) const
	{
		int i;
		for (i = 0; i < N; i++)
			if (arr[i] != X)
				return 1;
		return 0;
	}
	void Compare(const AB& X)
	{
		int ox[1010];
		int A, B, i, tempNum[10];
		A = B = 0;
		for (i = 0; i < 10; i++)
			tempNum[i] = 0;
		for (i = 0; i < N; i++) // A
		{
			ox[i] = 1;
			if (arr[i] == X.arr[i])
			{
				ox[i] = 0;
				tempNum[arr[i]]++;
				A++;
			}
		}
		for (i = 0; i < N; i++) // B
		{
			if (ox[i] && tempNum[X.arr[i]] < num[X.arr[i]])
			{
				tempNum[X.arr[i]]++;
				B++;
			}
		}
		printf("    (%d,%d)\n", A, B);
		return ;
	}
	friend istream& operator >> (istream& in, AB& X)
	{
		int i;
		for (i = 0; i < 10; i++)
			X.num[i] = 0;
		for (i = 0; i < N; i++)
		{
			cin >> X.arr[i];
			X.num[X.arr[i]]++;
		}
		return in;
	}
};

AB Game, Board;

int main()
{
	int t;
	for (t = 1; cin >> N, N; t++)
	{
		cin >> Game;
		printf("Game %d:\n", t);
		while (cin >> Board, Board != 0)
			Game.Compare(Board);
	}
}