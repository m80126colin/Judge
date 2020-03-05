#include <iostream>
using namespace std;

int main() {
	short a,b,c,d,e,f,g;
	for (cin>>a>>b>>c>>d;a||b||c||d;cin>>a>>b>>c>>d) {
		if (b>a) e = 40-b+a;
		else e = a-b;
		if (b>c) f = 40-b+c;
		else f = c-b;
		if (d>c) g = 40-d+c;
		else g = c-d;
		cout << 1080+9*(e+f+g) <<endl;
	}
}