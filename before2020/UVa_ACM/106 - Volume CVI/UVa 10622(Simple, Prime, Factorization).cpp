#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int i, m, flag;
	long long n;
	vector<int> V;
	while (cin >> n, n)
	{
		flag = 0;
		V.clear();
		if (n < 0)
		{
			flag = 1;
			n = -n;
		}
		for (i = 2; i <= sqrt((double) n); i++)
		{
			if (n % i == 0)
			{
				for (m = 0; n % i == 0; m++) n /= i;
				V.push_back(m);
			}
		}
		if (n > 1) V.push_back(1);
		m = V[0];
		for (i = 1; i < V.size(); i++)
			m = min(m, V[i]);
		if (flag)
			while ((m & 1) == 0) m >>= 1;
		printf("%d\n", m);
	}
}