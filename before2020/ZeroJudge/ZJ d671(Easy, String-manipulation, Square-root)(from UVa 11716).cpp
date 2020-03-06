/**
 *  @judge ZeroJudge
 *  @id d671
 *  @tag Easy, String manipulation, Square root
 */
#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

#define EPS 1e-7

int main()
{
	int t, L;
	string s;
	for (scanf("%d", &t), cin.ignore(1); t; t--)
	{
		getline(cin, s);
		L = sqrt((double) s.size()) + EPS;
		if (L * L == s.size())
		{
			int i, j;
			for (i = 0; i < L; i++)
				for (j = 0; j < L; j++)
					putchar(s[j * L + i]);
			puts("");
		}
		else puts("INVALID");
	}
}