/**
 *  @judge UVa
 *  @id 146
 *  @tag 1.0, Next permutation, Permutation, Recursive
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 60
char a[MAX];

int main()
{
	while (scanf("%s", a), a[0] != '#')
	{
		if (next_permutation(a, a + strlen(a)))
			puts(a);
		else puts("No Successor");
	}
}