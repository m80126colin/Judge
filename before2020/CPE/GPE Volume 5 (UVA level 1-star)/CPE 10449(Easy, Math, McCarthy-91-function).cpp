/**
 *  @judge CPE
 *  @id 10449
 *  @source UVa 10696
 * 
 *  @tag Easy, Math, McCarthy 91 function
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;

int main()
{
	while (cin >> n, n) printf("f91(%d) = %d\n", n, ((n>100) ? n-10 : 91) );
}