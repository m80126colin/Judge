#include <iostream>
using namespace std;

long long f[51];

int main() {
	int i;
	f[0]=1,f[1]=2;
	for (i=2;i<=50;i++) f[i]=f[i-1]+f[i-2];
	while (cin>>i) cout<<f[i]<<endl;
}