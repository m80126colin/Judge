#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	int n;
	string s[5] = {"Sheldon","Leonard","Penny","Rajesh","Howard"};
	while (scanf("%d", &n) != EOF)
	{
		int i;
		n--;
		for (i = 1; i * 5 <= n; i <<= 1)
			n -= i * 5;
		//printf("i = %d\n", i);
		//printf("ans = %d\n", n);
		cout << s[n / i] << endl;
	}
}