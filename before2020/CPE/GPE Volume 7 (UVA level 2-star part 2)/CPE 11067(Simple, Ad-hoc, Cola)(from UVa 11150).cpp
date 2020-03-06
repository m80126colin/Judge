/**
 *  @judge CPE
 *  @id 11067
 *  @tag Simple, Ad-hoc, Cola
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int a[6] = {0,1,3,4,6,7}, n;
	while (cin >> n) cout << n/6 * 9 + a[n%6] << endl;
}