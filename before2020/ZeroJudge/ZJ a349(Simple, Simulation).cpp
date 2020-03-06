/**
 *  @judge ZeroJudge
 *  @id a349
 *  @tag Simple, Simulation
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

int word[8], reg[4];
int r, s, s2;
string com;

void work()
{
	cin >> com >> r >> s;
	if (com == "LOAD") reg[r] = word[s];
	else if (com == "STORE") word[r] = reg[s];
	else if (com == "ADD")
	{
		cin >> s2;
		reg[r] = reg[s] + reg[s2];
	}
	else reg[r] = reg[s];
	return ;
}

int main()
{
	int ins, i;
	string com;
	while (cin.peek() != EOF)
	{
		for (i = 0; i < 8; i++)
			scanf("%d", &word[i]);
		memset(reg, 0, sizeof(reg));
		scanf("%d", &ins);
		for (i = 0; i < ins; i++)
			work();
		printf("%d\n%d\n", reg[0], word[0]);
	}
}