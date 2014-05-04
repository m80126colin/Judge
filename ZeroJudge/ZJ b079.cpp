#include <iostream>
using namespace std;

int main() {
	static long long a[1000000],i;
	a[0]=1;a[1]=1;
	for (i=2;i<1000000;i++) a[i]=a[i-a[i-1]]+a[i-1-a[i-2]];
	while (cin>>i&&i) cout<<a[i-1]<<endl;
}