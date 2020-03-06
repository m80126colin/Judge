/**
 *  @judge UVa
 *  @id 11827
 *  @tag Easy, Gcd
 */
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

inline int gcd(int a, int b)
{
	return (b)? gcd(b, a % b): a;
}

string s;
stringstream ss;

int main()
{
	int t, tmp, i, j;
	vector <int> a;
	for (scanf("%d", &t), cin.ignore(1); t; t--)
	{
		a.clear();
		getline(cin, s);
		ss.clear();
		ss.str(s);
		while (ss >> tmp)
			a.push_back(tmp);
		tmp = 1;
		if (a.size() >= 2)
		{
			tmp = gcd(a[0], a[1]);
			for (i = 0; i < a.size(); i++)
				for (j = i + 1; j < a.size(); j++)
					tmp = max(tmp, gcd(a[i], a[j]));
			printf("%d\n", tmp);
		}
	}
}