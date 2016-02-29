#include <iostream>
using namespace std;

int main() {
	int n,p,t,i;
	for (cin>>n;n;n--) {
		cin>>p;
		t=0;
		for (i=27;i>=1;i/=3) {
			t+=p/i;
			p%=i;
		}
		cout<<t<<endl;
	}
}