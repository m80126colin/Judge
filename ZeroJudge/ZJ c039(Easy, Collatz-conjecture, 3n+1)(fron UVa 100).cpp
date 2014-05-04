#include <iostream>
using namespace std;

int main() {
	int i,j,n,t1,t;
	while (cin>>i>>j) {
		cout<<i<<" "<<j<<" ";
		n=max(i,j);
		i=min(i,j);
		j=n;
		t1=0;
		for (i;i<=j;i++) {
			t=1;
			for (n=i;n!=1;t++) {
				if (n%2) n=3*n+1;
				else n/=2;
			}
			if (t>t1) t1=t;
		}
		cout<<t1<<endl;
	}
}