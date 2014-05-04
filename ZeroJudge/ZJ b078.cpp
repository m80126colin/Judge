#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n[1001],i,j;
	double s;
	while (cin>>n[0]&&n[0]) {
		i=n[0];
		for (s=0;n[0];n[0]--) {
			cin>>n[n[0]];
			s+=n[n[0]];
		}
		sort(n+1,n+i+1);
		s/=i;
		j=0;
		for (n[0]=1;n[0]<=i;n[0]++) {
			if (n[n[0]]<s) j++;
		}
		cout<<j<<endl;
	}
}