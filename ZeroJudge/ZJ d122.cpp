#include <iostream>
using namespace std;

int main() {
	long long n2,n5,n,i;
	while (cin>>n) {
		n2=n5=0;
		for (i=2;i<=n;i*=2) n2+=n/i;
		for (i=5;i<=n;i*=5) n5+=n/i;
		cout<<min(n2,n5)<<endl;
	}
}