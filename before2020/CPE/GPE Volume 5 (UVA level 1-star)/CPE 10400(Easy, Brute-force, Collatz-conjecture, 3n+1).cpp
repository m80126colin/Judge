/**
 *  @judge CPE
 *  @id 10400
 *  @source UVa 100
 * 
 *  @tag Easy, Brute force, Collatz conjecture, 3n+1
 */
#include <iostream>
using namespace std;

int main() {
	int i,j,t,a,b,k,n;
	while (cin>>i>>j) {
		if (i>=j) {
			a=j; b=i;
		}
		else {
			a=i; b=j;
		}
		k=0;
		while (a<=b) {
			n=a;
			t=1;
			while (n>1) {
				if (n%2) n=3*n+1;
				else n=n/2;
				t++;
			}
			if (t>k) k=t;
			a++;
		}
		cout<<i<<" "<<j<<" "<<k<<endl;
	}
}