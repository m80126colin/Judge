#include <iostream>
using namespace std;

int main() {
	unsigned long long a,b,c;
	while (cin>>a>>b) {
		while (a%b) {
			c=b;
			b=a%b;
			a=c;
		}
		cout<<b*b<<endl;
	}
}