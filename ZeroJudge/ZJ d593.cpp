#include <iostream>
using namespace std;

int main() {
	int n,i,j;
	for (cin>>n;n;n--) {
		for (cin>>i;i>=10;) {
			for (j=0;i;i/=10) j+=i%10;
			i=j;
		}
		cout<<i<<", ";
		if (i==2) cout<<"Yes\n";
		else cout<<"No\n";
	}
}