#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, m;

int main()
{
	int tmp;
	while (cin >> n >> m)
	{
		tmp = n;
		while (!(tmp % m)) tmp /= m;
		if (tmp > 1) printf("Boring!");
		else for (tmp = n; tmp; tmp /= m)
		{
			if (tmp != n) cout << " ";
			cout << tmp;
		}
		puts("");
	}
}