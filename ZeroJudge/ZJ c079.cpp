#include <iostream>
using namespace std;

int main() {
	int n,k,s,a,b;
	while (cin>>n>>k) {
		s=a=0;
		while (n) {
			s+=n;
			b=n%k;
			n=(n+a)/k;
			a=b;
		}
		cout<<s<<endl;
	}
}