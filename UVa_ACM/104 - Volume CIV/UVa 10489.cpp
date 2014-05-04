#include <iostream>
using namespace std;

int main() {
	long long t,b,s,g,a,c,n;
	for (cin>>t;t;t--) {
		c=0;
		for (cin>>n>>b;b;b--) {
			a=1;
			for (cin>>s;s;s--) {
				cin>>g;
				a*=g;
				a%=n;
			}
			c+=a;
			c%=n;
		}
		cout<<c%n<<endl;
	}
}