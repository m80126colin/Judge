#include <iostream>
using namespace std;

int bi(int x) {
	if (x/2) bi(x/2);
	cout<<x%2;
	return 0;
}

int main() {
	int n;
	while (cin>>n) {
		bi(n);
		cout<<endl;
	}
}