#include <iostream>
using namespace std;

int main() {
	unsigned long long n[91],i;
	n[0]=1,n[1]=2;
	for (i=2;i<=90;i++) n[i]=n[i-1]+n[i-2];
	while (cin>>i) cout<<n[i]<<endl;
}