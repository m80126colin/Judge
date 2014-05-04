#include <iostream>
#include <string>
using namespace std;

string dir = "NESW";
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
char maze[61][61];

int main()
{
	int i, j;
	int t, a, b;
	int x, y, face;
	char ins;
	for (cin >> t; t; t--)
	{
		cin >> a >> b;
		cin.get();
		for (i = 1; i <= a; i++)
		{
			for (j = 1; j <= b; j++)
				maze[i][j] = cin.get();
			cin.get();
		}
		cin >> x >> y;
		face = 0;
		while (cin >> ins)
		{
			if (ins == 'R')
			{
				face = (face + 1) % 4;
			}
			else if (ins == 'L')
			{
				face = (face + 3) % 4;
			}
			else if (ins == 'F')
			{
				if (x + dx[face] <= a && x + dx[face] >= 1 && y + dy[face] <= b && y + dy[face] >= 1 && maze[x + dx[face]][y + dy[face]] != '*')
				{
					x += dx[face];
					y += dy[face];
				}
			}
			else if (ins == 'Q')
				break;
		}
		cout << x << " " << y << " " << dir[face] << endl;
		if (t > 1) cout << endl;
	}
}