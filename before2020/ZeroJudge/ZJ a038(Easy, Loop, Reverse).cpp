#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin>>n) {
		while (n%10==0&&n) n/=10;
		if (n==0) cout<<0;
		for (n;n;n/=10) cout<<n%10;
		cout<<endl;
	}
}