/**
 *  @judge ZeroJudge
 *  @id a024
 *  @tag Easy, Gcd, Loop, Recursion
 */
#include <iostream>
using namespace std;

int m,n;

int gcd(int x,int y) {
	if (x%y) gcd(y,x%y);
	else n=y;
	return 0;
}

int main() {
	while (cin>>m>>n) {
		gcd(max(m,n),min(m,n));
		cout<<n<<endl;
	}
}