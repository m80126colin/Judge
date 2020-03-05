#include <iostream>
using namespace std;

int main() {
	int a,b,h,maxh,t,n;
	for (cin>>t;t;t--) {
		maxh=0;
		for (cin>>n,n*=2;n;n--) {
			cin>>a>>b>>h;
			maxh=max(maxh,h);
		}
		cout<<maxh<<endl;
	}
}