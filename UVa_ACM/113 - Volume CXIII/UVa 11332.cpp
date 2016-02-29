#include <iostream>
using namespace std;

int main() {
	int n,a;
	while (cin>>n&&n) {		
		while (n>=10) {
			a=0;
			while (n/10||n%10) {
				a+=n%10;
				n/=10;
			}
			n=a;
		}
		cout<<n<<endl;
	}
}