#include <iostream>
using namespace std;

long long s(long long x) {
	long long n=0;
	if (x<=0) return 0;
	while (x) {
		n+=(x/10)*45;
		if (x%10) n+=(1+x%10)*(x%10)/2;
		x/=10;
	}
	return n;
}

int main() {
	long long p,q;
	while (cin>>p>>q,p>=0&&q>=0) cout<<s(q)-s(p-1)<<endl;
}