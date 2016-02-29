#include <iostream>
using namespace std;

int main() {
	long long n[41],i;
	n[1]=1,n[2]=5,n[3]=11;
	for (i=4;i<=40;i++) n[i]=2*n[i-3]+4*n[i-2]+n[i-1];
	for (cin>>i;i;i--) {
		cin>>n[0];
		cout<<n[n[0]]<<endl;
	}
}