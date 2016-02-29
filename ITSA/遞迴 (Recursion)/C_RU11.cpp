#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
		cout << n * (n * n + 5) / 6 + 1 << endl;
}