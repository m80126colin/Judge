/**
 *  @judge TIOJ
 *  @id 1664
 *  @tag Easy, Arithmetic operator
 */
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

string day[7] = {
	"Sunday\n",
	"Monday\n",
	"Tuesday\n",
	"Wednesday\n",
	"Thursday\n",
	"Friday\n",
	"Saturday\n"
};
int x;

int main()
{
	while (scanf("%d", &x) != EOF)
		cout << day[(x + 5) % 7];
}