#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;

int main()
{
	freopen("q10934.txt", "w", stdout);
	int k, i;
	long long n, lc;
	srand(time(NULL));
	for (lc = 1, i = 0; i < 15; i++) lc *= 10;
	for (i = 0; i < 625411; i++)
	{
		k = rand() % 100 + 1;
		n = ((long long) rand() * rand() * rand() ) % lc + 1;
		if (n < k)
		{
			i--;
			continue;
		}
		cout << k << " " << n << endl;
	}
	cout << 0 << " " << rand() % 2147483647 + 1 << endl;
}