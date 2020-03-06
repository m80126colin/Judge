/**
 *  @judge ZeroJudge
 *  @id a002
 *  @tag Easy, Arithmetic Operation
 */
#include <iostream>
using namespace std;

int main() {
	int a, b;
	while (cin >> a >> b) {
		a += b;
		cout << a << endl;
	}
}