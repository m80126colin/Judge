#include <iostream>
using namespace std;

long long f(long long x) {
	long long count=0,w=1,i,j;
	if (x<0) return -1;
	while (x>=w) {
		i=x/(10*w),j=x/w;
		if (!(j%10)) {
			i--;
			count+=x%(10*w)+1;
		}
		count+=i*w;
		w*=10;
	}
	return count;
}

int main() {
	long long m,n;
	while (cin>>m>>n,m>=0&&n>=0) cout<<f(n)-f(m-1)<<endl;
}