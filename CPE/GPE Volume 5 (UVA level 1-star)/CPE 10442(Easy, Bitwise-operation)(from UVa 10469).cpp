#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, m;

int main()
{
	while (cin >> n >> m) cout << (n ^ m) << endl;
}