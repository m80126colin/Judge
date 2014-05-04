#include <iostream>
using namespace std;

int main() {
	long long n,t;
	while (cin>>n) {
		for (t=1;n;n--) t*=n;
		cout<<t<<endl;
	}
}