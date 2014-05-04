#include <iostream>
using namespace std;


int main()
{
	int L, W, x, y;
	while (cin >> L >> W >> x >> y, (L || W || x || y))
	{
		if ((L % x == 0 && W % y == 0) || (L % y == 0 && W % x == 0)) /* 整除才能剛好鋪滿 */
			cout << (L * W) / (x * y) << endl;
		else cout << "-1" << endl;
	}
}