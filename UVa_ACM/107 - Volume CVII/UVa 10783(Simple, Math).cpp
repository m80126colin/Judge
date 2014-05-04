#include <iostream>
using namespace std;

int main() {
	int t,a,b,i;
	cin>>t;
	for (i=1;i<=t;i++) {
		cin >> a;
		cin >> b;
		if (a%2) {
			if (b%2) cout << "Case " << i << ": " << ((b-a+2)*(a+b))/4 <<endl;
			else cout << "Case " << i << ": " << ((b-a+1)*(a+b-1))/4 <<endl;
		}
		else {
			if (b%2) cout << "Case " << i << ": " << ((b-a+1)*(a+b+1))/4 <<endl;
			else cout << "Case " << i << ": " << ((b-a)*(a+b))/4 <<endl; 
		}
	}
}