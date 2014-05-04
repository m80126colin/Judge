#include <iostream>
using namespace std;

int main() {
	int t,n,i,j;
	for (t=1;cin>>n,n>=0;t++) {
		i=1,j=0;
		while (i<n) i*=2,j++;
		printf("Case %d: %d\n",t,j);
	}
}