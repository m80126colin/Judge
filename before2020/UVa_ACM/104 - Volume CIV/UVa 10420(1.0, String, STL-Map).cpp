/**
 *  @judge UVa
 *  @id 10420
 *  @tag 1.0, String, STL Map
 */
#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

string s, t;
map<string, int> nation;
map<string, int>::iterator it;

int main()
{
	int n, i;
	while (scanf("%d", &n) != EOF)
	{
		nation.clear();
		for (i = 0; i < n; i++)
		{
			cin >> s;
			getline(cin, t);
			nation[s]++;
		}
		for (it = nation.begin(); it != nation.end(); it++)
			printf("%s %d\n", (it->first).c_str(), it->second);
	}
}