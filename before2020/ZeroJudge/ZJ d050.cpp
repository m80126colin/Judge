#include <iostream>
using namespace std;

int main() {
	int h;
	while (cin>>h) {
		if (h<15) h+=24;
		h-=15;
		cout<<h<<endl;
	}
}