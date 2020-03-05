#include <iostream>
using namespace std;

int main() {
	int t,s,n;
	while (cin>>t&&t) {
		for (s=0;t;t--) {
			cin>>n;
			s+=n*n;
		}
		cout<<s<<endl;
	}
}