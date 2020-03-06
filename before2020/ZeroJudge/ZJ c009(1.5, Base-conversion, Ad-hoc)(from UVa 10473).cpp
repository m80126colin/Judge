/**
 *  @judge ZeroJudge
 *  @id c009
 *  @tag 1.5, Number Base Conversion, Ad-hoc
 */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int num;
char str[110];

int main()
{
	while (scanf("%s", str) != EOF)
	{
		if (strlen(str) > 1 && str[0] == '0')
		{
			sscanf(str, "%X", &num);
			printf("%d\n", num);
		}
		else
		{
			sscanf(str, "%d", &num);
			if (num < 0) break;
			else printf("0x%X\n", num);
		}
	}
}