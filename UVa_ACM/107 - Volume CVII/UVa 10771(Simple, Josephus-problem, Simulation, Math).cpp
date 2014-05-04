#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m, k, i, now, temp;
	vector<int> Josephus;
	while (scanf("%d%d%d", &n, &m, &k), (n || m || k))
	{
		Josephus.clear();
		for (i = 0; i < n; i++)
			Josephus.push_back(0);
		for (i = 0; i < m; i++)
			Josephus.push_back(1);
		now = -1 + Josephus.size();
		while (Josephus.size() != 1)
		{
			now = (now + k) % Josephus.size();
			temp = Josephus[now];
			Josephus.erase(Josephus.begin() + now);
			now = (now + Josephus.size() - 1) % Josephus.size();
			now = (now + k) % Josephus.size();
			Josephus[now] = Josephus[now] ^ temp;
		}
		if (Josephus[0]) puts("Keka");
		else puts("Gared");
	}
}