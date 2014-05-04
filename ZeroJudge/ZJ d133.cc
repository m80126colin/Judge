#include <iostream>
using namespace std;

int main() {
	unsigned long long c[5]={1,5,10,25,50},n[30001],i,j;
	memset(n,0,sizeof(n));
	n[0]=1;
	for (i=0;i<5;i++) {
		for (j=c[i];j<=30000;j++) n[j]+=n[j-c[i]];
	}
	while (cin>>i) {
		if (n[i]==1) cout<<"There is only 1 way ";
		else cout<<"There are "<<n[i]<<" ways ";
		cout<<"to produce "<<i<<" cents change.\n";
	}
}