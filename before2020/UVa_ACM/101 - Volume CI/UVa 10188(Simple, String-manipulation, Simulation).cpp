/**
 *  @judge UVa
 *  @id 10188
 *  @tag Simple, String Manipulation, Simulation
 */
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

string AC, PE;
string Jac, Jpe;

int main()
{
	char ch;
	int n, m, t, ln;
	for (t = 1; scanf("%d", &n), n; t++)
	{
		while (cin.peek() != '\n') cin.ignore(1);
		cin.ignore(1);
		AC = PE = "";
		ln = 0;
		while (1)
		{
			ch = getchar();
			AC += ch;
			if (ch >= '0' && ch <= '9')
				PE += ch;
			if (ch == '\n')
				ln++;
			if (ln >= n)
				break;
		}
		scanf("%d", &m);
		while (cin.peek() != '\n') cin.ignore(1);
		cin.ignore(1);
		Jac = Jpe = "";
		ln = 0;
		while (1)
		{
			ch = getchar();
			Jac += ch;
			if (ch >= '0' && ch <= '9')
				Jpe += ch;
			if (ch == '\n')
				ln++;
			if (ln >= m)
				break;
		}
		printf("Run #%d: ", t);
		if (AC == Jac) puts("Accepted");
		else if (PE == Jpe) puts("Presentation Error");
		else puts("Wrong Answer");
	}
}