/**
 *  @judge UVa
 *  @id 145
 *  @tag Easy, Brute force
 */
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#define T 1440
#define A (  8       * 60)
#define B (( 6 + 12) * 60)
#define C ((10 + 12) * 60)
int Day[5] = {10, 25, 53, 87, 144};
int Eve[5] = { 6, 15, 33, 47,  80};
int Nit[5] = { 2,  5, 13, 17,  30};

int main()
{
	//freopen("145.out", "w+", stdout);
	int pay;
	char type;
	string tele;
	int h1, m1 , h2, m2;
	int day, eve, nit;
	while (cin >> type, type != '#')
	{
		pay = day = eve = nit = 0;
		cin >> tele >> h1 >> m1 >> h2 >> m2;
		m1 += h1 * 60 + 1;
		m2 += h2 * 60;
		if (m2 < m1) m2 += 24 * 60;
		for (; m1 <= m2; m1++)
		{
			if (m1 % T > A && m1 % T <= B) // day
			{
				day++;
				pay += Day[type - 'A'];
			}
			else if (m1 % T > B && m1 % T <= C) // eve
			{
				eve++;
				pay += Eve[type - 'A'];
			}
			else
			{
				nit++;
				pay += Nit[type - 'A'];
			}
		}
		printf("%10s%6d%6d%6d%3c%5d.%02d\n", tele.c_str(), day, eve, nit, type, pay / 100, pay % 100);
	}
}