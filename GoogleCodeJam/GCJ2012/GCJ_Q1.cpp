#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int main()
{
	//freopen("A-small-attempt2.in", "r+", stdin);
	//freopen("A-small-attempt2.out", "w+", stdout);
	int t, ctr, i, j;
	string ss;
	string ch = "yhesocvxduiglbkrztnwjpfmaq";
	cin >> t;
	cin.ignore(1);
	for (ctr = 1; ctr <= t; ctr++)
	{
		getline(cin, ss);
		i = ss.size();
		for (j = 0; j < i; j++)
			if (ss[j] >= 'a' && ss[j] <= 'z')
				ss[j] = ch[ss[j] - 'a'];
		printf("Case #%d: ", ctr);
		cout << ss << endl;
	}
}