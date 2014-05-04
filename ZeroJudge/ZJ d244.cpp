#include <iostream>
#include <map>
using namespace std;
map <int, int> M;
int main()
{
	int ans, tmp;
	for (ans = 0; cin >> tmp; M[tmp]++) if (M[tmp] % 3) ans ^= tmp;
	cout << ans << endl;
}