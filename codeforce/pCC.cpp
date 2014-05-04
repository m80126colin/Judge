#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
	{
		int i, j;
		unsigned char pre = 0, rev, npre, tmp;
		for (i = 0; i < s.size(); i++)
		{
			npre = 0;
			for (j = 0; j < 8; j++)
				npre |= ((pre & (1 << j)) >> j) << (7 - j);
			pre = npre;
			rev = 0;
			for (j = 0; j < 8; j++)
				rev |= ((s[i] & (1 << j)) >> j) << (7 - j);
			tmp = pre - rev;
			printf("%d\n", tmp);
			pre = rev;

			npre = 0;
			for (j = 0; j < 8; j++)
				npre |= ((pre & (1 << j)) >> j) << (7 - j);
			pre = npre;
			


		}
	}
}