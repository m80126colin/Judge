/**
 *  @judge CPE
 *  @id 11483
 *  @source UVa 11483
 * 
 *  @tag Easy, String, Brute force
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int ctr, n, i, j;
	string s;
	for (ctr = 1; cin >> n, n; ctr++)
	{
		cin.ignore(1);
		printf("Case %d:\n", ctr);
		puts("#include<string.h>\n#include<stdio.h>\nint main()\n{");
		for (i = 0; i < n; i++)
		{
			getline(cin, s);
			printf("printf(\"");
			for (j = 0; j < s.size(); j++)
			{
				if (s[j] == '\'') printf("\\\'");
				else if (s[j] == '\"') printf("\\\"");
				else if (s[j] == '\\') printf("\\\\");
				else putchar(s[j]);
			}
			puts("\\n\");");
		}
		puts("printf(\"\\n\");\nreturn 0;\n}");
	}
}