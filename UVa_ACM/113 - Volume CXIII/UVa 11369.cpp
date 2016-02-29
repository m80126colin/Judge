#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	int t,n,p[20000],q,r;
	for (cin>>t;t;t--) {
		cin>>n;
		for (q=0;q<n;q++) cin>>p[q];
		sort (p, p+n, greater<int>());
		r=0;
		for (q=2;q<n;q+=3) r+=p[q];
		cout<<r<<endl;
	}
}